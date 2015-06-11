#ifndef SYSTEM_H
#define SYSTEM_H

#include <stdint.h>
#include <stdio.h>

// Program start location
#define PROGRAM_START 0x200
// Memory size is 4096 bytes
#define MEMORY_SIZE 4096

// CPU
typedef struct cpu_t {
    // Registers
    uint8_t  A;         // Accumulator register
    uint16_t I;         // Memory address register
    uint16_t PC;        // Program counter register
} cpu_t;

// Full system: CPU and memory
typedef struct system_t {
    cpu_t *cpu;
    uint8_t memory[MEMORY_SIZE];
} system_t;

cpu_t *create_cpu();
void destroy_cpu(cpu_t *cpu);

system_t *create_system(FILE *file);
void destroy_system(system_t *system);

void handle_opcode(system_t *system, uint16_t opcode);

#endif
