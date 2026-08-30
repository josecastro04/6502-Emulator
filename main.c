#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include "instructions.h"
#include <stdlib.h>
#include <string.h>

void load_rom(struct CHIP *chip, char *filename){
    int fd = open(filename, O_RDONLY);
    if(fd == -1){
        perror("Error: file descriptor\n");
        exit(-1);
    }

    uint8_t buffer[256];
    int bytes;
    int index = 0;  
    while((bytes = read(fd, buffer, 256)) > 0){
        memcpy(chip->memory + index, buffer, bytes);
        index += bytes;
    }

    close(fd);
}

void init_chip(struct CHIP *chip){
    chip->pc = 0x400;//chip->memory[0xFFFC] | (chip->memory[0xFFFD] << 8);
    chip->ps = 0x34;
    chip->sp = 0xFF;
    chip->acc = chip->register_X = chip->register_Y = 0;
   // memset(chip->memory, 0, 0x10000);
}

int main(int argc, char **argv){
    CHIP chip;
    Instruction instructions[0xFF];

    load_instructions(instructions);
    init_chip(&chip);
    load_rom(&chip, argv[1]);
    
    uint16_t last_pc = 0xFFFF;
    uint8_t last_test_case = 0xFF;

    while(1){
        last_pc = chip.pc;
        decode(&chip, instructions);
        uint8_t current_test_case = chip.memory[0x0200];
        if(current_test_case != last_test_case){
            last_test_case = current_test_case;
            printf("A entrar no teste #%d (test_case=$%02X), PC=$%04X\n", 
               current_test_case, current_test_case, chip.pc);
        } 
        if(chip.pc == last_pc){
            if(current_test_case == 0xF0){
                printf("SUCESSO! Todos os testes passaram.\n");
            } else {
                printf("PRESO no teste #%d (test_case=$%02X). PC atual = $%04X\n", 
                       current_test_case, current_test_case, chip.pc);
            }
            break;
        }
    }

    return 0;
}