#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#include "../include/system.h"
#include "../include/opcodes.h"


void handle_opcode(system_t *system, uint16_t opcode)
{
    switch(opcode & 0xF000)
    {
    case 0x0:
        op_write(system, opcode);
        return;
    case 0x1:
        op_read(system, opcode);
        return;
    case 0x2:
        op_load(system, opcode);
        return;
    case 0x3:
        op_store(system, opcode);
        return;
    case 0x4:
        op_add(system, opcode);
        return;
    case 0x5:
        op_subtract(system, opcode);
        return;
    case 0x6:
        op_divide(system, opcode);
        return;
    case 0x7:
        op_multiply(system, opcode);
        return;
    case 0x8:
        op_branch(system, opcode);
        return;
    case 0x9:
        op_branchneg(system, opcode);
        return;
    case 0xA:
        op_branchzero(system, opcode);
        return;
    case 0xB:
        op_halt(system, opcode);
        return;
    }
}

// Return the opcode at a place in memory
uint16_t get_opcode(system_t *system, int index)
{
    uint16_t opcode;

    // Join 2 bytes
    opcode = system->memory[index];
    opcode <<= 8;
    opcode |= system->memory[index + 1];

    // Reverse endianness
    opcode = (opcode >> 8) | (opcode << 8);

    return opcode;
}

// Return the opcode being executed
uint16_t get_current_opcode(system_t *system)
{
    return get_opcode(system, system->cpu->PC);
}

// Initialize the entire system
system_t *create_system(FILE *file)
{
    system_t *system = calloc(1, sizeof(system_t));
    system->cpu = create_cpu();

    // Load a file into memory
    if(file)
    {
        fread(&system->memory[PROGRAM_START], 1, MEMORY_SIZE, file);
    }

    return system;
}

// Initialize the system
void init_system(system_t *system)
{
	init_cpu(system->cpu);
}

// Destroy the system and free its memory
void destroy_system(system_t *system)
{
    if(system)
    {
        if(system->cpu)
        {
            destroy_cpu(system->cpu);
        }
        free(system);
    }
}

// Create a new CPU
cpu_t *create_cpu()
{
    cpu_t *cpu = calloc(1, sizeof(cpu_t));
    return cpu;
}

void init_cpu(cpu_t *cpu)
{
    // Initialize the CPU registers
    cpu->A = 0;
    cpu->I = 0;
    cpu->PC = PROGRAM_START;
}

// Destroy the CPU and free its memory
void destroy_cpu(cpu_t *cpu)
{
    if(cpu)
    {
        free(cpu);
    }
}
