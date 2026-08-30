#include "instructions.h"
#include "addressing.h"
#include "chip.h"

#define OFFSET 0x0100

void load_instructions(Instruction *instructions){

    instructions[0x00] = (Instruction){
        .inst = BRK,
        .addressingMode = implied,
        .bytes = 0,
        .cycles = 7
    };

    instructions[0x01] = (Instruction){
        .inst = ORA,
        .addressingMode = pre_indexed_indirect,
        .bytes= 2,
        .cycles = 6
    };

    instructions[0x05] = (Instruction){
        .inst = ORA,
        .addressingMode = zero_page,
        .bytes= 2,
        .cycles = 3
    };

    instructions[0x06] = (Instruction){
        .inst = ASL,
        .addressingMode = zero_page,
        .bytes = 2,
        .cycles = 5
    };

    instructions[0x08] = (Instruction){
        .inst = PHP,
        .addressingMode = implied,
        .bytes = 1,
        .cycles = 3
    };

    instructions[0x09] = (Instruction){
        .inst = ORA,
        .addressingMode = immediate,
        .bytes= 2,
        .cycles = 2
    };

    instructions[0x0A] = (Instruction){
        .inst = ASL_acc,
        .addressingMode = accumulator,
        .bytes = 1,
        .cycles = 2
    };
    
    instructions[0x0D] = (Instruction){
        .inst = ORA,
        .addressingMode = absolute,
        .bytes= 3,
        .cycles = 4
    };

    instructions[0x0E] = (Instruction){
        .inst = ASL,
        .addressingMode = absolute,
        .bytes = 3,
        .cycles = 6
    };

    instructions[0x10] = (Instruction){
        .inst = BPL,
        .addressingMode = relative,
        .bytes = 2,
        .cycles = 2
    };

    instructions[0x11] = (Instruction){
        .inst = ORA,
        .addressingMode = post_indexed_indirect,
        .bytes= 2,
        .cycles = 5
    };

    instructions[0x15] = (Instruction){
        .inst = ORA,
        .addressingMode = indexed_zero_page_X,
        .bytes= 2,
        .cycles = 4
    };

    instructions[0x16] = (Instruction){
        .inst = ASL,
        .addressingMode = indexed_zero_page_X,
        .bytes = 2,
        .cycles = 6
    };

    instructions[0x18] = (Instruction){
        .inst = CLC,
        .addressingMode = implied,
        .bytes = 1,
        .cycles = 2
    };

    instructions[0x19] = (Instruction){
        .inst = ORA,
        .addressingMode = indexed_absolute_Y,
        .bytes= 3,
        .cycles = 4
    };

    instructions[0x1D] = (Instruction){
        .inst = ORA,
        .addressingMode = indexed_absolute_X,
        .bytes= 3,
        .cycles = 4
    }; 

    instructions[0x1E] = (Instruction){
        .inst = ASL,
        .addressingMode = indexed_absolute_X,
        .bytes = 3,
        .cycles = 7
    };

    instructions[0x20] = (Instruction){
        .inst = JSR,
        .addressingMode = absolute,
        .bytes = 0,//to not increment pc
        .cycles = 6
    };

    instructions[0x21] = (Instruction){
        .inst = AND,
        .addressingMode = pre_indexed_indirect,
        .bytes = 2,
        .cycles = 6
    };

    instructions[0x24] = (Instruction){
        .inst = BIT,
        .addressingMode = zero_page,
        .bytes = 2,
        .cycles = 3
    };

    instructions[0x25] = (Instruction){
        .inst = AND,
        .addressingMode = zero_page,
        .bytes = 2,
        .cycles = 3
    };

    instructions[0x26] = (Instruction){
        .inst = ROL,
        .addressingMode = zero_page,
        .bytes = 2,
        .cycles = 5
    };

    instructions[0x28] = (Instruction){
        .inst = PLP,
        .addressingMode = implied,
        .bytes = 1,
        .cycles = 4
    };

    instructions[0x29] = (Instruction){
        .inst = AND,
        .addressingMode = immediate,
        .bytes = 2, 
        .cycles = 2
    };

    instructions[0x2A] = (Instruction){
        .inst = ROL_acc,
        .addressingMode = accumulator,
        .bytes = 1,
        .cycles = 2
    };

    instructions[0x2C] = (Instruction){
        .inst = BIT,
        .addressingMode = absolute,
        .bytes = 3,
        .cycles = 4
    };

    instructions[0x2D] = (Instruction){
        .inst = AND,
        .addressingMode = absolute,
        .bytes = 3,
        .cycles = 4
    };

    instructions[0x2E] = (Instruction){
        .inst = ROL,
        .addressingMode = absolute,
        .bytes = 3,
        .cycles = 6
    };

    instructions[0x30] = (Instruction){
        .inst = BMI,
        .addressingMode = relative,
        .bytes = 2,
        .cycles = 2
    };

    instructions[0x31] = (Instruction){
        .inst = AND,
        .addressingMode = post_indexed_indirect,
        .bytes = 2,
        .cycles = 5
    };

    instructions[0x35] = (Instruction){
        .inst = AND,
        .addressingMode = indexed_zero_page_X,
        .bytes = 2,
        .cycles = 4
    };

    instructions[0x36] = (Instruction){
        .inst = ROL,
        .addressingMode = indexed_zero_page_X,
        .bytes = 2,
        .cycles = 6
    };

    instructions[0x38] = (Instruction){
        .inst = SEC,
        .addressingMode = implied,
        .bytes = 1,
        .cycles = 2
    };

    instructions[0x39] = (Instruction){
        .inst = AND,
        .addressingMode = indexed_absolute_Y,
        .bytes = 3,
        .cycles = 4
    };

    instructions[0x3D] = (Instruction){
        .inst = AND,
        .addressingMode = indexed_absolute_X,
        .bytes = 3,
        .cycles = 4
    };

    instructions[0x3E] = (Instruction){
        .inst = ROL,
        .addressingMode = indexed_absolute_X,
        .bytes = 3,
        .cycles = 7
    };

    instructions[0x40] = (Instruction){
        .inst = RTI,
        .addressingMode = implied,
        .bytes = 0, //to not increment pc
        .cycles = 6
    };

    instructions[0x41] = (Instruction){
        .inst = EOR,
        .addressingMode = pre_indexed_indirect,
        .bytes = 2,
        .cycles = 6
    }; 

    instructions[0x45] = (Instruction){
        .inst = EOR,
        .addressingMode = zero_page,
        .bytes = 2,
        .cycles = 3
    };
    
    instructions[0x46] = (Instruction){
        .inst = LSR,
        .addressingMode = zero_page,
        .bytes = 2,
        .cycles = 5
    };
    
    instructions[0x48] = (Instruction){
        .inst = PHA,
        .addressingMode = implied,
        .bytes = 1,
        .cycles = 3
    };
    
    instructions[0x49] = (Instruction){
        .inst = EOR,
        .addressingMode = immediate,
        .bytes = 2,
        .cycles = 2
    };

    instructions[0x4A] = (Instruction){
        .inst = LSR_acc,
        .addressingMode = accumulator,
        .bytes = 1,
        .cycles = 2
    };

    instructions[0x4C] = (Instruction){
        .inst = JMP,
        .addressingMode = absolute,
        .bytes = 0, //to not increment pc
        .cycles = 3
    };
    
    instructions[0x4D] = (Instruction){
        .inst = EOR,
        .addressingMode = absolute,
        .bytes = 3,
        .cycles = 4
    };

    instructions[0x4E] = (Instruction){
        .inst = LSR,
        .addressingMode = absolute,
        .bytes = 3,
        .cycles = 7
    };

    instructions[0x50] = (Instruction){
        .inst = BVC,
        .addressingMode = relative,
        .bytes = 2,
        .cycles = 2
    };
    
    instructions[0x51] = (Instruction){
        .inst = EOR,
        .addressingMode = post_indexed_indirect,
        .bytes = 2,
        .cycles = 5
    };

    instructions[0x55] = (Instruction){
        .inst = EOR,
        .addressingMode = indexed_zero_page_X,
        .bytes = 2,
        .cycles = 4
    };

    instructions[0x56] = (Instruction){
        .inst = LSR,
        .addressingMode = indexed_zero_page_X,
        .bytes = 2,
        .cycles = 6
    };

    instructions[0x58] = (Instruction){
        .inst = CLI,
        .addressingMode = implied,
        .bytes = 1,
        .cycles = 2
    };
    
    instructions[0x59] = (Instruction){
        .inst = EOR,
        .addressingMode = indexed_absolute_Y,
        .bytes = 3,
        .cycles = 4
    };

    instructions[0x5D] = (Instruction){
        .inst = EOR,
        .addressingMode = indexed_absolute_X,
        .bytes = 3,
        .cycles = 4
    };

    instructions[0x5E] = (Instruction){
        .inst = LSR,
        .addressingMode = indexed_absolute_X,
        .bytes = 3,
        .cycles = 7
    };

    instructions[0x60] = (Instruction){
        .inst = RTS,
        .addressingMode = implied,
        .bytes = 0, //to not increment pc
        .cycles = 6
    };

    instructions[0x61] = (Instruction){
        .inst = ADC,
        .addressingMode = pre_indexed_indirect,
        .bytes = 2,
        .cycles = 6
    };

    instructions[0x65] = (Instruction){
        .inst = ADC,
        .addressingMode = zero_page,
        .bytes = 2,
        .cycles = 3
    };

    instructions[0x66] = (Instruction){
        .inst = ROR,
        .addressingMode = zero_page,
        .bytes = 2,
        .cycles = 5
    };

    instructions[0x68] = (Instruction){
        .inst = PLA,
        .addressingMode = implied,
        .bytes = 1,
        .cycles =4
    };

    instructions[0x69] = (Instruction){
        .inst = ADC,
        .addressingMode = immediate,
        .bytes = 2,
        .cycles = 2
    };

    instructions[0x6A] = (Instruction){
        .inst = ROR_acc,
        .addressingMode = accumulator,
        .bytes = 1,
        .cycles = 2
    };

    instructions[0x6C] = (Instruction){
        .inst = JMP,
        .addressingMode = indirect,
        .bytes = 0, //to not increment pc
        .cycles = 5
    };

    instructions[0x6D] = (Instruction){
        .inst = ADC,
        .addressingMode = absolute,
        .bytes = 3,
        .cycles = 4
    };

    instructions[0x6E] = (Instruction){
        .inst = ROR,
        .addressingMode = absolute,
        .bytes = 3,
        .cycles = 6
    };

    instructions[0x70] = (Instruction){
        .inst = BVS,
        .addressingMode = relative,
        .bytes = 2,
        .cycles = 2
    };

    instructions[0x71] = (Instruction){
        .inst = ADC,
        .addressingMode = post_indexed_indirect,
        .bytes = 2,
        .cycles = 5
    };

    instructions[0x75] = (Instruction){
        .inst = ADC,
        .addressingMode = indexed_zero_page_X,
        .bytes = 2,
        .cycles = 4
    };

    instructions[0x76] = (Instruction){
        .inst = ROR,
        .addressingMode = indexed_zero_page_X,
        .bytes = 2,
        .cycles = 6
    };

    instructions[0x78] = (Instruction){
        .inst = SEI,
        .addressingMode = implied,
        .bytes = 1,
        .cycles = 2
    };

    instructions[0x79] = (Instruction){
        .inst = ADC,
        .addressingMode = indexed_absolute_Y,
        .bytes = 3,
        .cycles = 4
    };

    instructions[0x7D] = (Instruction){
        .inst = ADC,
        .addressingMode = indexed_absolute_X,
        .bytes = 3,
        .cycles = 4
    };

    instructions[0x7E] = (Instruction){
        .inst = ROR,
        .addressingMode = indexed_absolute_X,
        .bytes = 3,
        .cycles = 7
    };
    
    instructions[0x81] = (Instruction){
        .inst = STA,
        .addressingMode = pre_indexed_indirect,
        .bytes = 2,
        .cycles = 6
    };

    instructions[0x84] = (Instruction){
        .inst = STY,
        .addressingMode = zero_page,
        .bytes = 2,
        .cycles = 3
    };

    instructions[0x85] = (Instruction){
        .inst = STA,
        .addressingMode = zero_page,
        .bytes = 2,
        .cycles = 3,
    };

    instructions[0x86] = (Instruction){
        .inst = STX,
        .addressingMode = zero_page,
        .bytes = 2,
        .cycles = 3
    };

    instructions[0x88] = (Instruction){
        .inst = DEY,
        .addressingMode = implied,
        .bytes = 1,
        .cycles =2
    };
    
    instructions[0x8A] = (Instruction){
        .inst = TXA,
        .addressingMode = implied,
        .bytes = 1,
        .cycles = 2
    };

    instructions[0x8C] = (Instruction){
        .inst = STY,
        .addressingMode = absolute,
        .bytes = 3,
        .cycles = 4
    };

    instructions[0x8D] = (Instruction){
        .inst = STA,
        .addressingMode = absolute,
        .bytes = 3,
        .cycles = 4
    };

    instructions[0x8E] = (Instruction){
        .inst = STX,
        .addressingMode = absolute,
        .bytes = 3,
        .cycles = 4
    };

    instructions[0x90] = (Instruction){
        .inst = BCC,
        .addressingMode = relative,
        .bytes = 2,
        .cycles = 2
    };

    instructions[0x91] = (Instruction){
        .inst = STA,
        .addressingMode = post_indexed_indirect,
        .bytes = 2,
        .cycles = 6
    };

    instructions[0x94] = (Instruction){
        .inst = STY,
        .addressingMode = indexed_zero_page_X,
        .bytes = 2,
        .cycles = 4
    };

    instructions[0x95] = (Instruction){
        .inst = STA,
        .addressingMode = indexed_zero_page_X,
        .bytes = 2,
        .cycles = 4
    };

    instructions[0x96] = (Instruction){
        .inst = STX,
        .addressingMode = indexed_zero_page_Y,
        .bytes = 2,
        .cycles = 4
    };

    instructions[0x98] = (Instruction){
        .inst = TYA,
        .addressingMode = implied,
        .bytes = 1,
        .cycles = 2
    };
    
    instructions[0x9A] = (Instruction){
        .inst = TXS,
        .addressingMode = implied,
        .bytes = 1,
        .cycles = 2
    };

    instructions[0x9D] = (Instruction){
        .inst = STA,
        .addressingMode = indexed_absolute_X,
        .bytes = 3,
        .cycles = 5
    };

    instructions[0x99] = (Instruction){
        .inst = STA,
        .addressingMode = indexed_absolute_Y,
        .bytes = 3,
        .cycles = 5
    };

    instructions[0xA0] = (Instruction){
        .inst = LDY,
        .addressingMode = immediate,
        .bytes = 2,
        .cycles = 2
    };

    instructions[0xA1] = (Instruction){
        .inst = LDA,
        .addressingMode = pre_indexed_indirect,
        .bytes = 2,
        .cycles = 6
    };

    instructions[0xA2] = (Instruction){
        .inst = LDX,
        .addressingMode = immediate,
        .bytes = 2,
        .cycles = 2
    };

    instructions[0xA4] = (Instruction){
        .inst = LDY,
        .addressingMode = zero_page,
        .bytes = 2,
        .cycles = 3
    };
    
    instructions[0xA5] = (Instruction){
        .inst = LDA,
        .addressingMode = zero_page,
        .bytes = 2,
        .cycles = 3
    };

    instructions[0xA6] = (Instruction){
        .inst = LDX,
        .addressingMode = zero_page,
        .bytes = 2,
        .cycles = 3
    };

    instructions[0xA8] = (Instruction){
        .inst = TAY,
        .addressingMode = implied,
        .bytes = 1,
        .cycles = 2
    };

    instructions[0xA9] = (Instruction){
        .inst = LDA,
        .addressingMode = immediate,
        .bytes = 2,
        .cycles = 2
    };

    instructions[0xAA] = (Instruction){
        .inst = TAX,
        .addressingMode = implied,
        .bytes = 1,
        .cycles = 2
    };

    instructions[0xAC] = (Instruction){
        .inst = LDY,
        .addressingMode = absolute,
        .bytes = 3,
        .cycles = 4
    };

    instructions[0xAD] = (Instruction){
        .inst = LDA,
        .addressingMode = absolute,
        .bytes = 3,
        .cycles = 4
    };

    instructions[0xAE] = (Instruction){
        .inst = LDX,
        .addressingMode = absolute,
        .bytes = 3,
        .cycles = 4
    };

    instructions[0xB0] = (Instruction){
        .inst = BCS,
        .addressingMode = relative,
        .bytes = 2,
        .cycles = 2
    };

    instructions[0xB1] = (Instruction){
        .inst = LDA,
        .addressingMode = post_indexed_indirect,
        .bytes = 2,
        .cycles = 5
    };

    instructions[0xB4] = (Instruction){
        .inst = LDY,
        .addressingMode = indexed_zero_page_X,
        .bytes = 2,
        .cycles = 4
    };

    instructions[0xB5] = (Instruction){
        .inst = LDA,
        .addressingMode = indexed_zero_page_X,
        .bytes = 2,
        .cycles = 4
    };

    instructions[0xB6] = (Instruction){
        .inst = LDX,
        .addressingMode = indexed_zero_page_Y,
        .bytes = 2,
        .cycles = 4
    };
   
    instructions[0xB8] = (Instruction){
        .inst = CLV,
        .addressingMode = implied,
        .bytes = 1,
        .cycles = 2
    };
    
    instructions[0xB9] = (Instruction){
        .inst = LDA,
        .addressingMode = indexed_absolute_Y,
        .bytes = 3,
        .cycles = 4
    };

    instructions[0xBA] = (Instruction){
        .inst = TSX,
        .addressingMode = implied,
        .bytes = 1,
        .cycles = 2
    };
    
    instructions[0xBC] = (Instruction){
        .inst = LDY,
        .addressingMode = indexed_absolute_X,
        .bytes = 3,
        .cycles = 4
    };

    instructions[0xBD] = (Instruction){
        .inst = LDA,
        .addressingMode = indexed_absolute_X,
        .bytes = 3,
        .cycles = 4
    };

    instructions[0xBE] = (Instruction){
        .inst = LDX,
        .addressingMode = indexed_absolute_Y,
        .bytes = 3,
        .cycles = 4
    };

    instructions[0xC0] = (Instruction){
        .inst = CPY,
        .addressingMode = immediate,
        .bytes = 2,
        .cycles = 2
    };

    instructions[0xC1] = (Instruction){
        .inst = CMP,
        .addressingMode = pre_indexed_indirect,
        .bytes = 2,
        .cycles = 6
    };

    instructions[0xC4] = (Instruction){
        .inst = CPY,
        .addressingMode = zero_page,
        .bytes = 2,
        .cycles = 3
    };

    instructions[0xC5] = (Instruction){
        .inst = CMP,
        .addressingMode = zero_page,
        .bytes = 2,
        .cycles = 3
    };

    instructions[0xC6] = (Instruction){
        .inst = DEC,
        .addressingMode = zero_page,
        .bytes = 2,
        .cycles = 5
    };

    instructions[0xC8] = (Instruction){
        .inst = INY,
        .addressingMode = implied,
        .bytes = 1,
        .cycles = 2
    };

    instructions[0xC9] = (Instruction){
        .inst = CMP,
        .addressingMode = immediate,
        .bytes = 2,
        .cycles = 2
    };

    instructions[0xCA] = (Instruction){
        .inst = DEX,
        .addressingMode = implied,
        .bytes = 1,
        .cycles = 2
    };

    instructions[0xCC] = (Instruction){
        .inst = CPY,
        .addressingMode = absolute,
        .bytes = 3,
        .cycles = 4
    };

    instructions[0xCD] = (Instruction){
        .inst = CMP,
        .addressingMode = absolute,
        .bytes = 3,
        .cycles = 4
    };

    instructions[0xCE] = (Instruction){
        .inst = DEC,
        .addressingMode = absolute,
        .bytes = 3,
        .cycles = 6
    };

    instructions[0xD0] = (Instruction){
        .inst = BNE,
        .addressingMode = relative,
        .bytes = 2,
        .cycles = 2
    };

    instructions[0xD1] = (Instruction){
        .inst = CMP,
        .addressingMode = post_indexed_indirect,
        .bytes = 2,
        .cycles = 5
    };

    instructions[0xD5] = (Instruction){
        .inst = CMP,
        .addressingMode = indexed_zero_page_X,
        .bytes = 2,
        .cycles = 4
    };

    instructions[0xD6] = (Instruction){
        .inst = DEC,
        .addressingMode = indexed_zero_page_X,
        .bytes = 2,
        .cycles = 6
    };

    instructions[0xD8] = (Instruction){
        .inst = CLD,
        .addressingMode = implied,
        .bytes = 1,
        .cycles = 2
    };

    instructions[0xD9] = (Instruction){
        .inst = CMP,
        .addressingMode = indexed_absolute_Y,
        .bytes = 3,
        .cycles = 4
    };

    instructions[0xDD] = (Instruction){
        .inst = CMP,
        .addressingMode = indexed_absolute_X,
        .bytes = 3,
        .cycles = 4
    };

    instructions[0xDE] = (Instruction){
        .inst = DEC,
        .addressingMode = indexed_absolute_X,
        .bytes = 3,
        .cycles = 7
    };

    instructions[0xE0] = (Instruction){
        .inst = CPX,
        .addressingMode = immediate,
        .bytes = 2,
        .cycles = 2
    };

    instructions[0xE1] = (Instruction){
        .inst = SBC,
        .addressingMode = pre_indexed_indirect,
        .bytes = 2,
        .cycles = 6
    };

    instructions[0xE4] = (Instruction){
        .inst = CPX,
        .addressingMode = zero_page,
        .bytes = 2,
        .cycles = 3
    };

    instructions[0xE5] = (Instruction){
        .inst = SBC,
        .addressingMode = zero_page,
        .bytes = 2,
        .cycles = 3
    };

    instructions[0xE6] = (Instruction){
        .inst = INC,
        .addressingMode = zero_page,
        .bytes = 2,
        .cycles = 5
    };

    instructions[0xE8] = (Instruction){
        .inst = INX,
        .addressingMode = implied,
        .bytes = 1,
        .cycles = 2
    };

    instructions[0xE9] = (Instruction){
        .inst = SBC,
        .addressingMode = immediate,
        .bytes = 2,
        .cycles = 2
    };

    instructions[0xEA] = (Instruction){
        .inst = NOP,
        .addressingMode = implied,
        .bytes = 1,
        .cycles = 2
    };
    
    instructions[0xEC] = (Instruction){
        .inst = CPX,
        .addressingMode = absolute,
        .bytes = 3,
        .cycles = 4
    };

    instructions[0xED] = (Instruction){
        .inst = SBC,
        .addressingMode = absolute,
        .bytes = 3,
        .cycles = 4
    };

    instructions[0xEE] = (Instruction){
        .inst = INC,
        .addressingMode = absolute,
        .bytes = 3,
        .cycles = 6
    };

    instructions[0xF0] = (Instruction){
        .inst = BEQ,
        .addressingMode = relative,
        .bytes = 2,
        .cycles = 2
    };

    instructions[0xF1] = (Instruction){
        .inst = SBC,
        .addressingMode = post_indexed_indirect,
        .bytes = 2,
        .cycles = 5
    };

    instructions[0xF5] = (Instruction){
        .inst = SBC,
        .addressingMode = indexed_zero_page_X,
        .bytes = 2,
        .cycles = 4
    };

    instructions[0xF6] = (Instruction){
        .inst = INC,
        .addressingMode = indexed_zero_page_X,
        .bytes = 2,
        .cycles = 6
    };

    instructions[0xF8] = (Instruction){
        .inst = SED,
        .addressingMode = implied,
        .bytes = 1,
        .cycles = 2
    };

    instructions[0xF9] = (Instruction){
        .inst = SBC,
        .addressingMode = indexed_absolute_Y,
        .bytes = 3,
        .cycles = 4
    };

    instructions[0xFD] = (Instruction){
        .inst = SBC,
        .addressingMode = indexed_absolute_X,
        .bytes = 3,
        .cycles = 4
    };

    instructions[0xFE] = (Instruction){
        .inst = INC,
        .addressingMode = indexed_absolute_X,
        .bytes = 3,
        .cycles = 7
    };
}

void LDA(struct CHIP *chip, uint16_t address){
    chip->acc = chip->memory[address];
    updatePS(&chip->ps, FLAG_Z | FLAG_N, chip->acc);
}

void LDX(struct CHIP *chip, uint16_t address){
    chip->register_X = chip->memory[address];
    updatePS(&chip->ps, FLAG_Z | FLAG_N, chip->register_X);
}

void LDY(struct CHIP *chip, uint16_t address){
    chip->register_Y = chip->memory[address];
    updatePS(&chip->ps, FLAG_Z | FLAG_N, chip->register_Y);
}

void STA(struct CHIP *chip, uint16_t address){ 
    chip->memory[address] = chip->acc;
}

void STX(struct CHIP *chip, uint16_t address){ 
    chip->memory[address] = chip->register_X;
}

void STY(struct CHIP *chip, uint16_t address){ 
    chip->memory[address] = chip->register_Y;
}

void TAX(struct CHIP *chip, uint16_t address){
    chip->register_X = chip->acc;
    uint8_t mask = FLAG_Z | FLAG_N;
    updatePS(&chip->ps, mask, chip->register_X);
}

void TAY(struct CHIP *chip, uint16_t address){
    chip->register_Y = chip->acc;
    uint8_t mask = FLAG_Z | FLAG_N;
    updatePS(&chip->ps, mask, chip->register_Y);
}

void TSX(struct CHIP *chip, uint16_t address){
    chip->register_X = chip->sp;
    uint8_t mask = FLAG_Z | FLAG_N;
    updatePS(&chip->ps, mask, chip->register_X);
}

void TXA(struct CHIP *chip, uint16_t address){
    chip->acc = chip->register_X;
    uint8_t mask = FLAG_Z | FLAG_N;
    updatePS(&chip->ps, mask, chip->acc);
}

void TXS(struct CHIP *chip, uint16_t address){
    chip->sp = chip->register_X;
}

void TYA(struct CHIP *chip, uint16_t address){
    chip->acc = chip->register_Y;
    uint8_t mask = FLAG_Z | FLAG_N;
    updatePS(&chip->ps, mask, chip->acc);
}

void PHA(struct CHIP *chip, uint16_t address){
    chip->memory[OFFSET + chip->sp] = chip->acc;
    chip->sp--;   
}

void PHP(struct CHIP *chip, uint16_t address){
    chip->memory[OFFSET + chip->sp] = chip->ps | (FLAG_B | 0X20);
    chip->sp--;
}

void PLA(struct CHIP *chip, uint16_t address){
    chip->sp++;
    chip->acc = chip->memory[OFFSET + chip->sp];
    uint8_t mask = FLAG_Z | FLAG_N;
    updatePS(&chip->ps, mask, chip->acc);
}

void PLP(struct CHIP *chip, uint16_t address){
    chip->sp++;
    chip->ps = (chip->memory[OFFSET + chip->sp]) | 0x20;
}

void DEC(struct CHIP *chip, uint16_t address){
    chip->memory[address]--;
    updatePS(&chip->ps, FLAG_Z | FLAG_N, chip->memory[address]);
}

void DEX(struct CHIP *chip, uint16_t address){
    chip->register_X--;
    updatePS(&chip->ps, FLAG_Z | FLAG_N, chip->register_X);
}

void DEY(struct CHIP *chip, uint16_t address){
    chip->register_Y--;
    updatePS(&chip->ps, FLAG_Z | FLAG_N, chip->register_Y);
}

void INC(struct CHIP *chip, uint16_t address){
    chip->memory[address]++;
    updatePS(&chip->ps, FLAG_Z | FLAG_N, chip->memory[address]);
}

void INX(struct CHIP *chip, uint16_t address){
    chip->register_X++;
    updatePS(&chip->ps, FLAG_Z | FLAG_N, chip->register_X);
}

void INY(struct CHIP *chip, uint16_t address){
    chip->register_Y++;
    updatePS(&chip->ps, FLAG_Z | FLAG_N, chip->register_Y);
}

void ADC_Decimal(struct CHIP *chip, uint16_t address){
    uint8_t low_acc = chip->acc & 0xF;
    uint8_t hi_acc = chip->acc >> 4 & 0xF;
    uint8_t low_mem = chip->memory[address] & 0xF;
    uint8_t hi_mem = chip->memory[address] >> 4 & 0xF;
    uint8_t carry = chip->ps & FLAG_C;
    uint8_t result_low = low_acc + low_mem + carry;
    uint8_t carry_result = 0;
    if(result_low > 9){
        carry_result = 1;
        result_low += 6;
        result_low &= 0xF;
    }

    uint8_t result_hi = hi_acc + hi_mem + carry_result;
    carry_result = 0;
    if(result_hi > 9){
        carry_result = 1;
        result_hi += 6;
        result_hi &= 0xF;
    }
    uint8_t mask = FLAG_N | FLAG_Z;
    uint8_t result = (result_hi << 4) + result_low;
    if(((chip->acc ^ chip->memory[address]) & 0x80) == 0 && ((chip->acc ^ result) & 0x80) != 0) mask |= FLAG_V;
    else chip->ps &= ~FLAG_V;
    chip->acc = result;
    if(carry_result) chip->ps |= FLAG_C;
    else chip->ps &= ~FLAG_C;
    updatePS(&chip->ps, mask, chip->acc);
}

//Todo: ADC_Binary
//Colocar um if para ver se a flag do carry está ativa para fazer o ADC_Decimal
void ADC(struct CHIP *chip, uint16_t address){
    if(chip->ps & FLAG_D){
        ADC_Decimal(chip, address);
        return;
    }
    
    int16_t result = (int16_t)chip->acc + (int16_t)chip->memory[address] + (chip->ps & FLAG_C);
    uint8_t mask = FLAG_Z | FLAG_N;
    if(((chip->acc ^ chip->memory[address]) & 0x80) == 0 && ((chip->acc ^ result) & 0x80) != 0) mask |= FLAG_V;
    else chip->ps &= ~FLAG_V;
    if(result & 0xFF00) mask |= FLAG_C;
    else chip->ps &= ~FLAG_C;
    chip->acc = (uint8_t)result;
    updatePS(&chip->ps, mask, chip->acc);
}

void SBC_Decimal(struct CHIP *chip, uint16_t address){
    uint8_t memory_value = chip->memory[address];
    uint8_t carry = chip->ps & FLAG_C;
    uint8_t result_carry = (chip->acc - memory_value - (1 - carry)) >= 0 ? 1 : 0;
    uint8_t low_acc = chip->acc & 0xF;
    uint8_t hi_acc = chip->acc >> 4 & 0xF;
    uint8_t low_mem = memory_value & 0xF;
    uint8_t hi_mem = memory_value >> 4 & 0xF;

    int8_t result_low = low_acc - low_mem - (1 - carry);
    if(result_low < 0){
        result_low += 10;
        carry = 1;
    }else{
        carry = 0;
    }

    int8_t result_hi = hi_acc - hi_mem - carry;
    if(result_hi < 0) result_hi += 10;
    uint8_t mask = FLAG_Z | FLAG_N;
    uint8_t result = (result_hi << 4) + result_low;
    if(((chip->acc ^ chip->memory[address]) & 0x80) != 0 && ((chip->acc ^ result) & 0x80) != 0) mask |= FLAG_V;
    else chip->ps &= ~FLAG_V;

    chip->acc = result;
    if(result_carry == 1) chip->ps |= FLAG_C;
    else chip->ps &= ~FLAG_C;
    updatePS(&chip->ps, mask, chip->acc);
}

void SBC(struct CHIP *chip, uint16_t address){

    if(chip->ps & FLAG_D){
        SBC_Decimal(chip, address);
        return;
    }

    int16_t result = (int16_t)chip->acc - (int16_t)chip->memory[address] - (1 - (chip->ps & FLAG_C));
    uint8_t mask = FLAG_Z | FLAG_N;
    if(((chip->acc ^ chip->memory[address]) & 0x80) != 0 && ((chip->acc ^ result) & 0x80) != 0) mask |= FLAG_V;
    else chip->ps &= ~FLAG_V;
    if(result >= 0) mask |= FLAG_C;
    else chip->ps &= ~FLAG_C;
    chip->acc = (uint8_t)result;
    updatePS(&chip->ps, mask, chip->acc);
}

void AND(struct CHIP *chip, uint16_t address){
    chip->acc &= chip->memory[address];
    uint8_t mask = FLAG_Z | FLAG_N;
    updatePS(&chip->ps, mask, chip->acc);   
}

void EOR(struct CHIP *chip, uint16_t address){
    chip->acc ^= chip->memory[address];
    uint8_t mask = FLAG_Z | FLAG_N;
    updatePS(&chip->ps, mask, chip->acc); 
}

void ORA(struct CHIP *chip, uint16_t address){
    chip->acc |= chip->memory[address];
    uint8_t mask = FLAG_Z | FLAG_N;
    updatePS(&chip->ps, mask, chip->acc); 
}

void ASL(struct CHIP *chip, uint16_t address){
    uint8_t mask = FLAG_Z | FLAG_N;
    if(chip->memory[address] & 0x80) chip->ps |= FLAG_C;
    else chip->ps &= ~ FLAG_C;
    chip->memory[address] <<= 1;
    updatePS(&chip->ps, mask, chip->memory[address]);
}

//TODO: refactor
void ASL_acc(struct CHIP *chip, uint16_t address){
    uint8_t mask = FLAG_Z | FLAG_N;
    if(chip->acc & 0x80) chip->ps |= FLAG_C;
    else chip->ps &= ~FLAG_C;
    chip->acc <<= 1;
    updatePS(&chip->ps, mask, chip->acc);
}

void LSR(struct CHIP *chip, uint16_t address){
    if(chip->memory[address] & FLAG_C) chip->ps |= FLAG_C;
    else chip->ps &= ~FLAG_C;
    chip->memory[address] >>= 1;
    chip->ps &= ~FLAG_N;
    updatePS(&chip->ps, FLAG_Z, chip->memory[address]);
}

void LSR_acc(struct CHIP *chip, uint16_t address){
    if(chip->acc & FLAG_C) chip->ps |= FLAG_C;
    else chip->ps &= ~FLAG_C;
    chip->acc >>= 1;
    chip->ps &= ~FLAG_N;
    updatePS(&chip->ps, FLAG_Z, chip->acc);
}

void ROL(struct CHIP *chip, uint16_t address){
    uint8_t mask = FLAG_Z | FLAG_N;
    uint8_t carry = chip->ps & FLAG_C;
    if(chip->memory[address] & 0x80) chip->ps |= FLAG_C;
    else chip->ps &= ~FLAG_C;
    chip->memory[address] <<= 1;
    chip->memory[address] |= carry;
    updatePS(&chip->ps, mask, chip->memory[address]);
}

void ROL_acc(struct CHIP *chip, uint16_t address){
    uint8_t mask = FLAG_Z | FLAG_N;
    uint8_t carry = chip->ps & FLAG_C;
    if(chip->acc & 0x80) chip->ps |= FLAG_C;
    else chip->ps &= ~FLAG_C;
    chip->acc <<= 1;
    chip->acc |= carry;
    updatePS(&chip->ps, mask, chip->acc);
}

void ROR(struct CHIP *chip, uint16_t address){
    uint8_t mask = FLAG_Z | FLAG_N;
    uint8_t carry = chip->ps & FLAG_C;
    if(chip->memory[address] & 0x01) chip->ps |= FLAG_C;
    else chip->ps &= ~FLAG_C;
    chip->memory[address] >>= 1;
    chip->memory[address] |= (carry << 7);
    updatePS(&chip->ps, mask, chip->memory[address]);
}

void ROR_acc(struct CHIP *chip, uint16_t address){
    uint8_t mask = FLAG_Z | FLAG_N;
    uint8_t carry = chip->ps & FLAG_C;
    if(chip->acc & 0x01) chip->ps |= FLAG_C;
    else chip->ps &= ~FLAG_C;
    chip->acc >>= 1;
    chip->acc |= (carry << 7);
    updatePS(&chip->ps, mask, chip->acc);
}

void CLC(struct CHIP *chip, uint16_t address){
    chip->ps &= ~FLAG_C;
}

void CLD(struct CHIP *chip, uint16_t address){
    chip->ps &= ~FLAG_D;
}

void CLI(struct CHIP *chip, uint16_t address){
    chip->ps &= ~FLAG_I;
}

void CLV(struct CHIP *chip, uint16_t address){
    chip->ps &= ~FLAG_V;
}

void SEC(struct CHIP *chip, uint16_t address){
    chip->ps |= FLAG_C;
}

void SED(struct CHIP *chip, uint16_t address){
    chip->ps |= FLAG_D;
}

void SEI(struct CHIP *chip, uint16_t address){
    chip->ps |= FLAG_I;
}

void CMP(struct CHIP *chip, uint16_t address){
    uint8_t result = chip->acc - chip->memory[address];
    uint8_t mask = FLAG_Z | FLAG_N;
    chip->ps &= ~FLAG_C;
    if(chip->acc >= chip->memory[address])
        chip->ps |= FLAG_C;
    updatePS(&chip->ps, mask, result);
}

void CPX(struct CHIP *chip, uint16_t address){
    uint8_t result = chip->register_X - chip->memory[address];
    uint8_t mask = FLAG_Z | FLAG_N;
    chip->ps &= ~FLAG_C;
    if(chip->register_X >= chip->memory[address])
        chip->ps |= FLAG_C;
    updatePS(&chip->ps, mask, result);
}

void CPY(struct CHIP *chip, uint16_t address){
    uint8_t result = chip->register_Y - chip->memory[address];
    uint8_t mask = FLAG_Z | FLAG_N;
    chip->ps &= ~FLAG_C;
    if(chip->register_Y >= chip->memory[address])
        chip->ps |= FLAG_C;
    updatePS(&chip->ps, mask, result);
}

void BIT(struct CHIP *chip, uint16_t address){
    uint8_t result = chip->acc & chip->memory[address];

    if(chip->memory[address] & FLAG_N) chip->ps |= FLAG_N;
    else chip->ps &= ~FLAG_N;

    if(chip->memory[address] & FLAG_V) chip->ps |= FLAG_V;
    else chip->ps &= ~FLAG_V;

    updatePS(&chip->ps, FLAG_Z, result);
}

void BCC(struct CHIP *chip, uint16_t address){
    if(!(chip->ps & FLAG_C)) chip->pc += (int8_t)address;
}

void BCS(struct CHIP *chip, uint16_t address){
    if(chip->ps & FLAG_C) chip->pc += (int8_t)address;
}

void BEQ(struct CHIP *chip, uint16_t address){
    if(chip->ps & FLAG_Z) chip->pc += (int8_t)address;
}

void BMI(struct CHIP *chip, uint16_t address){
    if(chip->ps & FLAG_N) chip->pc += (int8_t)address;
}

void BNE(struct CHIP *chip, uint16_t address){
    if(!(chip->ps & FLAG_Z)) chip->pc += (int8_t)address;
}

void BPL(struct CHIP *chip, uint16_t address){
    if(!(chip->ps & FLAG_N)) chip->pc += (int8_t)address;
}

void BVC(struct CHIP *chip, uint16_t address){
    if(!(chip->ps & FLAG_V)) chip->pc += (int8_t)address;
}

void BVS(struct CHIP *chip, uint16_t address){
    if(chip->ps & FLAG_V) chip->pc += (int8_t)address;
}

void JMP(struct CHIP *chip, uint16_t address){
    chip->pc = address;
}

void JSR(struct CHIP *chip, uint16_t address){
    uint16_t updated_pc = chip->pc + 2;
    chip->memory[OFFSET + chip->sp] = (updated_pc >> 8) & 0xFF;
    chip->sp--;
    chip->memory[OFFSET + chip->sp] = updated_pc & 0xFF;
    chip->sp--;
    chip->pc = address;
}

void RTS(struct CHIP *chip, uint16_t address){
    chip->sp++;
    chip->pc = chip->memory[OFFSET + chip->sp];
    chip->sp++;
    chip->pc |= chip->memory[OFFSET + chip->sp] << 8;
    chip->pc += 1;
}

void BRK(struct CHIP *chip, uint16_t address){
    uint16_t updated_pc = chip->pc + 2;
    chip->memory[OFFSET + chip->sp] = (updated_pc >> 8) & 0xFF;
    chip->sp--;
    chip->memory[OFFSET + chip->sp] = updated_pc & 0xFF;
    chip->sp--;
    chip->memory[OFFSET + chip->sp] = chip->ps | FLAG_B | 0x20;
    chip->sp--;

    chip->ps |= FLAG_I;

    chip->pc = chip->memory[0xFFFE] | (chip->memory[0xFFFF] << 8);
}

void RTI(struct CHIP *chip, uint16_t address){
    chip->sp++;
    chip->ps = chip->memory[OFFSET + chip->sp];
    chip->sp++;
    chip->pc = chip->memory[OFFSET + chip->sp];
    chip->sp++;
    chip->pc |= chip->memory[OFFSET + chip->sp] << 8;
};

void NOP(struct CHIP *chip, uint16_t address){
    //"waste" 2 cycles
}