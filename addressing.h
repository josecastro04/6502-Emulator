#include <stdint.h>
#include <stdio.h>

typedef struct AddressingData{
    uint16_t *pc;
    uint8_t *memory;
    uint8_t reg_x;
    uint8_t reg_y;
    uint8_t acc;
}AddressingData;

uint16_t implied(AddressingData data);
uint16_t accumulator(AddressingData data);
uint16_t immediate(AddressingData data);
uint16_t absolute(AddressingData data);
uint16_t zero_page(AddressingData data);
uint16_t indexed_absolute_X(AddressingData data);
uint16_t indexed_absolute_Y(AddressingData data);
uint16_t indexed_zero_page_X(AddressingData data);
uint16_t indexed_zero_page_Y(AddressingData data);
uint16_t indirect(AddressingData data);
uint16_t pre_indexed_indirect(AddressingData data);
uint16_t post_indexed_indirect(AddressingData data);
uint16_t relative(AddressingData data);