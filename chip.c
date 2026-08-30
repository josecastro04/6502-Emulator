#include "chip.h"
#include "addressing.h"
#include "instructions.h"

void updatePS(uint8_t *ps_value, uint8_t mask, uint8_t value){
    //turn off
    *ps_value &= ~mask;

    if(mask & FLAG_C){
        *ps_value |= FLAG_C;
    }

    if(mask & FLAG_Z){
        *ps_value |= (value == 0x00 ? FLAG_Z : 0x00);
    }
    if(mask & FLAG_I){
        *ps_value |= FLAG_I;
    }

    if(mask & FLAG_V){
        *ps_value |= FLAG_V;
    }

    if(mask & FLAG_N){
        *ps_value |= (value & FLAG_N);
    }
}

void decode(CHIP *chip, Instruction *instructions){
    uint8_t opcode = chip->memory[chip->pc];
    Instruction exec = instructions[opcode];

    AddressingData data = {
        .acc = chip->acc,
        .pc = &chip->pc,
        .memory = chip->memory,
        .reg_x = chip->register_X,
        .reg_y = chip->register_Y
    };
    
    uint16_t value = (exec.addressingMode)(data);
    (exec.inst)(chip, value);

    chip->pc += exec.bytes;
}