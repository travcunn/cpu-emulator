# cpu-emulator
Experimental CPU emulator written in C

#### Goals
- Learn more about CPU emulation
- Build a compiler
- Build a unix-like operating system
- Build a filesystem
- Build a network stack
- Implement Unix tools usually found in /bin (ls, cat, etc)
- Implement a simple web server
- Run a CPU emulator inside another emulator

#### Architecture
**CPU**
```c
typedef struct cpu_t {
    // Registers
    uint8_t  A;         // Accumulator register
    uint16_t I;         // Memory address register
    uint16_t PC;        // Program counter register
} cpu_t;
```
**Full system (CPU + memory)**
```c
typedef struct system_t {
    cpu_t *cpu;
    uint8_t memory[MEMORY_SIZE];
} system_t;
```
