#ifndef STACK_H
#define STACK_H

#include <stdbool.h>
#include <string.h>

#define MAX 128
typedef char str256[257];

typedef struct StackOperatorType{
    str256 items[MAX];
    int top;
} StackOperator;

typedef struct StackOperandType{
    int items[MAX];
    int top;
} StackOperand;

void createStackOperator(StackOperator *stack);
bool pushOperator(StackOperator *stack, str256 operator);
bool popOperator(StackOperator *stack, str256 operator);
bool topOperator(StackOperator *stack, str256 operator);
bool StackOperatorEmpty(StackOperator *stack);
bool StackOperatorFull(StackOperator *s);

void createStackOperand(StackOperand *stack);
bool pushOperand(StackOperand *stack, int operand);
bool popOperand(StackOperand *stack, int *operand);
bool topOperand(StackOperand *stack, int *operand);
bool StackOperandEmpty(StackOperand *stack);
bool StackOperandFull(StackOperand *stack);

#endif