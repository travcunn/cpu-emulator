#include <stdio.h>
#include <stdlib.h>

#include "../include/main.h"
#include "../include/system.h"

#define DUMP_MEMORY_LINEWRAP 20


/*
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

        // Wrap every 20 lines
        if ((i+1) % DUMP_MEMORY_LINEWRAP == 0)
        {
            printf("\n");
        }
    }
}
*/

int main(int argc, char *argv[])
{
    FILE *rom_file;

    // check if a rom file parameter was provided
    if(argc < 2 || argv[1] == NULL)
    {
        printf("em: error: no input files\n");
        return 1;
    }

    // Load a rom file
    rom_file = fopen(argv[1], "rb");
	if(!rom_file)
    {
        printf("Error loading rom file: %s\n", argv[1]);
        return 1;
    }

    system_t *system = create_system(rom_file);
    if(!system)
    {
        printf("Error creating a base system\n");
        if(rom_file)
        {
            fclose(rom_file);
        }
        return 1;
    }

    //TODO Create execution loop here

    if(system)
    {
        destroy_system(system);
    }
    if(rom_file)
    {
        fclose(rom_file);
    }
	
    return 0;
}
