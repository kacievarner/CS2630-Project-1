#include "Phase3.h"
#include "InstructionFactory.h"
#include "Instruction.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void translate_instructions(struct ArrayList *tals, uint32_t machineCode[]) {
	//for every tal instruction
	for(int i = 0; i < size(tals); i++) {
    	struct Instruction currentInstruction = get(tals, i); //instruction that is currently being translated
    	uint32_t binary = 0; //temp binary int
    	//translation for addu							 
    	if(currentInstruction.instruction_id == addu) {
      		uint32_t opcode = 0x0;
      		uint32_t rs = currentInstruction.rs << 21;
      		uint32_t rt = currentInstruction.rt << 16;
      		uint32_t rd = currentInstruction.rd << 11;
      		uint32_t shamt = 0x0;
      		uint32_t funct = 33;
      		binary = (opcode | rs | rt | rd | shamt | funct);      
      		machineCode[i] = binary;
    	}
    	//translation for addiu
    	else if(currentInstruction.instruction_id == addiu) {
      		uint32_t opcode = 9 << 26;
      		uint32_t rs = currentInstruction.rs << 21;
      		uint32_t rt = currentInstruction.rt << 16;
      		uint32_t imm = (currentInstruction.immediate & 0xFFFF);
      		binary = (opcode | rs | rt | imm);      
      		machineCode[i] = binary;
    	}
    	//translation for or
    	else if(currentInstruction.instruction_id == or) {
      		uint32_t opcode = 0x0;
      		uint32_t rs = currentInstruction.rs << 21;
      		uint32_t rt = currentInstruction.rt << 16;
      		uint32_t rd = currentInstruction.rd << 11;
      		uint32_t shamt = 0x0;
      		uint32_t funct = 37;
      		binary = (opcode | rs | rt | rd | shamt | funct);      
      		machineCode[i] = binary;
    	}
    	//translation for beq
    	else if(currentInstruction.instruction_id == beq) {
      		uint32_t opcode = 4 << 26;
      		uint32_t rs = currentInstruction.rs << 21;
      		uint32_t rt = currentInstruction.rt << 16;
      		uint32_t imm = (currentInstruction.immediate & 0xFFFF);
      		binary = (opcode | rs | rt | imm);      
      		machineCode[i] = binary;
    	}
    	//translation for bne
    	else if(currentInstruction.instruction_id == bne) {
      		uint32_t opcode = 5 << 26;
      		uint32_t rs = currentInstruction.rs << 21;
      		uint32_t rt = currentInstruction.rt << 16;
      		uint32_t imm = (currentInstruction.immediate & 0xFFFF);
      		binary = (opcode | rs | rt | imm);
      		machineCode[i] = binary;
    	}
    	//translation for slt
    	else if(currentInstruction.instruction_id == slt) {
      		uint32_t opcode = 0x0;
      		uint32_t rs = currentInstruction.rs << 21;
      		uint32_t rt = currentInstruction.rt << 16;
      		uint32_t rd = currentInstruction.rd << 11;
      		uint32_t shamt = 0x0;
      		uint32_t funct = 42;
      		binary = (opcode | rs | rt | rd | shamt | funct);      
      		machineCode[i] = binary;
    	}
    	//translation for sll
    	else if(currentInstruction.instruction_id == sll) {
      		uint32_t opcode = 0x0;
      		uint32_t rs = currentInstruction.rs << 21;
      		uint32_t rt = currentInstruction.rt << 16;
      		uint32_t rd = currentInstruction.rd << 11;
      		uint32_t shamt = currentInstruction.shift_amount << 6;
      		uint32_t funct = 0x0;
      		binary = (opcode | rs | rt | rd | shamt | funct);      
      		machineCode[i] = binary;
    	}
    	//translation for lui
    	else if(currentInstruction.instruction_id == lui) {
      		uint32_t opcode = 15 << 26;
      		uint32_t rs = currentInstruction.rs << 21;
      		uint32_t rt = currentInstruction.rt << 16;
      		uint32_t imm = (currentInstruction.immediate & 0xFFFF);
      		binary = (opcode | rs | rt | imm);     
      		machineCode[i] = binary;
    	}
    	//translation for ori
    	else if(currentInstruction.instruction_id == ori) {
      		uint32_t opcode = 13 << 26;
      		uint32_t rs = currentInstruction.rs << 21;
      		uint32_t rt = currentInstruction.rt << 16;
      		uint32_t imm = (currentInstruction.immediate & 0xFFFF);
      		binary = (opcode | rs | rt | imm);      
      		machineCode[i] = binary;
    	}   
  	}
}
