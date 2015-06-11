#include <stdio.h>
#include <stdlib.h>

#include "../include/opcodes.h"

// Write a word from a specific location in memory to the terminal
void op_write(system_t *system, uint16_t opcode)
{
    printf("%.8d\n", system->memory[opcode]);
}

// Read a word from the terminal into a specific location in memory
void op_read(system_t *system, uint16_t opcode)
{
    int operand;
    scanf("%d", &operand);

    system->memory[opcode] = operand;
}

// Load a word from a specific location in memory into the accumulator
void op_load(system_t *system, uint16_t opcode)
{
    system->cpu->A = system->memory[opcode];
}

// Store a word from the acumulator into a specific location in memory
void op_store(system_t *system, uint16_t opcode)
{
    system->memory[opcode] = system->cpu->A;
}

// Add a word from a specific location in memory to the word in the
// accumulator
void op_add(system_t *system, uint16_t opcode)
{
    system->cpu->A += system->memory[opcode];
}

// Subtract a word from a specific location in memory from the word in the
// accumulator
void op_subtract(system_t *system, uint16_t opcode)
{
    system->cpu->A -= system->memory[opcode];
}

// Divide a word from a specific location in memory into the word in the
// accumulator
void op_divide(system_t *system, uint16_t opcode)
{
    system->cpu->A = system->cpu->A / system->memory[opcode];
}

// Multiply a word from a specific location in memory into the word in the
// accumulator
void op_multiply(system_t *system, uint16_t opcode)
{
    system->cpu->A = system->cpu->A * system->memory[opcode];
}

// Branch to a specific location in memory
void op_branch(system_t *system, uint16_t opcode)
{
    system->cpu->I = opcode;
}

// Branch to a specific location in memory if the accumulator is negative
void op_branchneg(system_t *system, uint16_t opcode)
{
    if (system->cpu->A < 0)
    {
        op_branch(system, opcode);
    }
}

// Branch to a specific location in memory if the accumulator is zero
void op_branchzero(system_t *system, uint16_t opcode)
{
    if (system->cpu->A == 0)
    {
        op_branch(system, opcode);
    }
}

// Halt, the program has completed its task
void op_halt(system_t *system, uint16_t opcode)
{
    exit(0);
}

