#include <stdint.h>
#include "addressing.h"

//Flags
#define FLAG_C 0x01
#define FLAG_Z 0x02
#define FLAG_I 0x04
#define FLAG_D 0x08
#define FLAG_B 0x10
#define FLAG_V 0x40
#define FLAG_N 0x80

typedef struct CHIP{
    //Program Counter
    uint16_t pc;
    
    //Stack Pointer
    uint8_t sp;
    
    //Accumulator
    uint8_t acc;
    
    //Index Register X 
    uint8_t register_X;

    //Index Register Y
    uint8_t register_Y;

    //Processor Status
    uint8_t ps;

    //Memory 64Kb
    uint8_t memory[0x10000];
}CHIP;

typedef struct Instruction{
    void (*inst)(CHIP *, uint16_t value);
    uint16_t (*addressingMode)(AddressingData);
    uint8_t bytes;
    uint8_t cycles;
}Instruction;


void updatePS(uint8_t *ps_value, uint8_t mask, uint8_t value);
void decode(struct CHIP *chip, Instruction *instructions);