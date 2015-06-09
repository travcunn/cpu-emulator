#include <stdio.h>
#include <stdlib.h>

#define MEMORY_SIZE 1000
#define OPCODE_SIZE 2
#define OPERAND_SIZE 2

// Registers
int accumulator;
int instructionCounter;
int instructionRegister;
int opCode;
int operand;

// Memory
int memory [MEMORY_SIZE];

// Write a word from a specific location in memory to the terminal
void write(int location)
{
    char opcode[OPERAND_SIZE];
    char operand[OPCODE_SIZE];
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

// Dumps registers and memory to the the terminal
void dumpMemory()
{
    // Display Registers
    printf("accumulator: %.4d\n", accumulator);
    printf("instructionCounter: %.4d\n", instructionCounter);
    printf("instructionRegister: %.4d\n", instructionRegister);
    printf("opCode: %.4d\n", opCode);
    printf("operand: %.4d\n", operand);
    printf("\n");

    int i = 0;
    for (i; i<MEMORY_SIZE; i++)
    {
        // Display memory value
        printf("%.4d ", memory[i]);

        if ((i+1) % 20 == 0)
        {
            printf("\n");
        }
    }
}

int main(int argc, const char* argv[] )
{
    dumpMemory();
    read(1);
    read(2);
    load(1);
    multiply(2);
    store(3);
    write(3);
    dumpMemory();
}
