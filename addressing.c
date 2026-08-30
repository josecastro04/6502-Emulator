#include "addressing.h"

#define OFFSET_0P 0xA

uint16_t implied(AddressingData data){
    return 0;
}

uint16_t accumulator(AddressingData data){
    return data.acc;
}

uint16_t immediate(AddressingData data){
    return *data.pc + 1;
}

uint16_t absolute(AddressingData data){
    uint16_t address = data.memory[*data.pc + 2] << 8 | data.memory[*data.pc + 1];
    return address;
}

uint16_t zero_page(AddressingData data){
    uint16_t address = data.memory[*data.pc + 1];
    address = (address & 0xFF);
    return address;
}

uint16_t indexed_absolute_X(AddressingData data){
    uint16_t address = (data.memory[*data.pc + 2] << 8 | data.memory[*data.pc + 1]) + data.reg_x;
    return address;
}

uint16_t indexed_absolute_Y(AddressingData data){
    uint16_t address = (data.memory[*data.pc + 2] << 8 | data.memory[*data.pc + 1]) + data.reg_y;
    return address;
}

uint16_t indexed_zero_page_X(AddressingData data){
    uint16_t address = data.memory[*data.pc + 1] + data.reg_x;
    return address & 0xFF;
}

uint16_t indexed_zero_page_Y(AddressingData data){
    uint16_t address = data.memory[*data.pc + 1] + data.reg_y;
    return address& 0xFF;
}

uint16_t indirect(AddressingData data){
    uint16_t pointer = data.memory[*data.pc + 2] << 8 | data.memory[*data.pc + 1];
    uint16_t address = data.memory[pointer + 1] << 8 | data.memory[pointer];
    return address;
}

uint16_t pre_indexed_indirect(AddressingData data){
    uint16_t pointer = (data.memory[*data.pc + 1] + data.reg_x) & 0xFF;
    uint16_t address = data.memory[pointer + 1] << 8 | data.memory[pointer];
    return address;
}

uint16_t post_indexed_indirect(AddressingData data){
    uint16_t pointer = data.memory[*data.pc + 1];
    uint16_t address = (data.memory[(pointer + 1) & 0xFF] << 8 | data.memory[pointer & 0xFF]) + data.reg_y;
    return address;
}

uint16_t relative(AddressingData data){
    uint16_t address = data.memory[*data.pc + 1];
    return address;
}