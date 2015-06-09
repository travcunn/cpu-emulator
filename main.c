#include <stdio.h>
#include <stdlib.h>
#define SIZE 2

// Registers
int accumulator;
int instructionCounter;
int instructionRegister;
int opCode;
int operand;

// Memory
int memory [1000];

// Write a word from a specific location in memory to the terminal
void write(int location)
{
    char opcode[SIZE];
    char operand[SIZE];
    printf("%.4d\n", memory[location]);
}

// Read a word from the terminal into a specific location in memory
void read(int location)
{
    int operand;

    scanf("%d", &operand);

    memory[location] = operand;
}

// Load a word from a specific location in memory into the accumulator
void load(int location)
{
    accumulator = memory[location];
}

// Store a word from the acumulator into a specific location in memory
void store(int location)
{
    memory[location] = accumulator;
}

// Add a word from a specific location in memory to the word in the
// accumulator
void add(int location)
{
    accumulator += memory[location];
}

// Subtract a word from a specific location in memory from the word in the
// accumulator
void subtract(int location)
{
    accumulator -= memory[location];
}

// Divide a word from a specific location in memory into the word in the
// accumulator
void divide(int location)
{
    accumulator = accumulator / memory[location];
}

// Multiply a word from a specific location in memory into the word in the
// accumulator
void multiply(int location)
{
    accumulator = accumulator * memory[location];
}

// Branch to a specific location in memory
void branch(int operand)
{
    instructionCounter = operand;
}

// Branch to a specific location in memory if the accumulator is negative
void branchneg(int location)
{
    if (accumulator < 0)
    {
        branch(location);
    }
}

// Branch to a specific location in memory if the accumulator is zero
void branchzero(int location)
{
    if (accumulator == 0)
    {
        branch(location);
    }
}

// Halt, the program has completed its task
void halt()
{
    exit(0);
}

int main(int argc, const char* argv[] )
{
    read(1);
    read(2);
    load(1);
    multiply(2);
    store(3);
    write(3);
}
