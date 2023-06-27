//Kacie Varner & Tiffanie Duong
//Fall 2020

#include "Phase1.h"
#include "ArrayList.h"
#include "Instruction.h"
#include "InstructionFactory.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void mal_to_tal(struct ArrayList *mals, struct ArrayList *tals) {
	int upperImmediate, lowerImmediate, temp;
	for (int i = 0; i < size(mals); i++){
    	struct Instruction getInstruction = get(mals, i);
    	//addiu and subsequent instruction conversion
    	if ((getInstruction.instruction_id == addiu) && ((getInstruction.immediate >= 32767)||(getInstruction.immediate <= -32767))){
        	upperImmediate = ((getInstruction.immediate >> 16) & 0xFFFF);
       		lowerImmediate = ((getInstruction.immediate) & 0xFFFF);
       		temp = 1;
            addLast(tals, (CreateLui_lab(temp, upperImmediate, getInstruction.label)));
            addLast(tals, (CreateOri(temp, temp, lowerImmediate)));
            addLast(tals, (CreateAddu(getInstruction.rt, getInstruction.rs, temp)));
    	}
    	//ori and subsequent instruction conversion
    	else if ((getInstruction.instruction_id == ori) && ((getInstruction.immediate > 65535)||(getInstruction.immediate < 0))){
            upperImmediate = ((getInstruction.immediate >> 16) & 0xFFFF);
       		lowerImmediate = ((getInstruction.immediate) & 0xFFFF);
       		temp = 1;
            addLast(tals, (CreateLui_lab(temp, upperImmediate, getInstruction.label)));
            addLast(tals, (CreateOri(temp, temp, lowerImmediate)));
            addLast(tals, (CreateOr(getInstruction.rt, getInstruction.rs, temp)));
    	}
    	//mov instruction conversion
    	else if (getInstruction.instruction_id == mov){
        	addLast(tals, (CreateAddu_lab(getInstruction.rd, getInstruction.rs, getInstruction.rt, getInstruction.label)));
    	}
    	//bge instruction conversion
    	else if (getInstruction.instruction_id == bge){
        	temp = 1;
        	addLast(tals, (CreateSlt_lab(temp, getInstruction.rt, getInstruction.rs, getInstruction.label)));
        	addLast(tals, (CreateBeq_lab(temp, 0, getInstruction.branch_label, getInstruction.label)));
    	}
    	//blt instruction conversion
    	else if (getInstruction.instruction_id == blt){
        	if(getInstruction.rt > getInstruction.rs){
       		 temp = 1;
        	}
        	addLast(tals, (CreateSlt_lab(temp, getInstruction.rt, getInstruction.rs, getInstruction.label)));
        	addLast(tals, (CreateBne_lab(temp, 0, getInstruction.branch_label, getInstruction.label)));
    	}
    	//Already tal so add instruction to list
    	else{
        	addLast(tals, getInstruction);
    	}  	 
	}
}
