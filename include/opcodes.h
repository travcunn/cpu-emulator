#ifndef OPCODES_H
#define OPCODES_H

#include "system.h"

void op_read(system_t *system, uint16_t opcode);
void op_write(system_t *system, uint16_t opcode);
void op_load(system_t *system, uint16_t opcode);
void op_store(system_t *system, uint16_t opcode);
void op_add(system_t *system, uint16_t opcode);
void op_subtract(system_t *system, uint16_t opcode);
void op_divide(system_t *system, uint16_t opcode);
void op_multiply(system_t *system, uint16_t opcode);
void op_branch(system_t *system, uint16_t opcode);
void op_branchneg(system_t *system, uint16_t opcode);
void op_branchzero(system_t *system, uint16_t opcode);
void op_halt(system_t *system, uint16_t opcode);

#endif
