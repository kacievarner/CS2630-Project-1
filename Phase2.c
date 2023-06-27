#include "Phase2.h"
#include "InstructionFactory.h"
#include "Instruction.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void resolve_addresses(struct ArrayList *unresolved, uint32_t first_pc, struct ArrayList *resolved) {
	struct Instruction *instruction = unresolved->elements; //unresolved element pointer
	int immediateForPC; //temp value that holds the pc element
	//for each unresolved instruction
	for(int i = 0; i < size(unresolved); i++){
		//if there is no label or branch label
		if(!strcmp(instruction[i].label, "") == 0) {
			//for each unresolved instruction
			for(int j = 0; j < size(unresolved); j++){
				//PC value used for branching
	      		immediateForPC = (i-(j+1));
	      		//if there is no label or branch label, then analyze instructions for their immediate values
	      		if(strcmp(instruction[i].label, instruction[j].branch_label) == 0){
	      			//defines the beq immediate instruction
	        		if(instruction[j].instruction_id == beq) {
	          			struct Instruction temp = CreateBeq_imm(instruction[j].rs, instruction[j].rt, immediateForPC);
		  	  			instruction[j] = temp;
	        		}
	        		//defines the bne immediate instruction
					if(instruction[j].instruction_id == bne){
                  		struct Instruction temp = CreateBne_imm(instruction[j].rs, instruction[j].rt, immediateForPC);
		  				instruction[j] = temp;
	        		}
	      		}
	    	}
	  	}
	}
	//Adds all resolved instructions to the list
	for(int x = 0; x < size(unresolved); x++){
		addLast(resolved, instruction[x]);
	}
}

