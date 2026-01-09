#include "stack.h"

void createStackOperator(StackOperator *stack){
    stack->top = -1;
}

bool pushOperator(StackOperator *stack, const char* operator){
    bool status = false;
    if (stack->top < MAX - 1)
    {
        strncpy(stack->items[++(stack->top)], operator, 2);
        stack->items[stack->top][2] = '\0';
        status = !status;
    }
    return status;
}

bool popOperator(StackOperator *stack, char* operator){
    bool status = false;
    if (stack->top >= 0)
    {
        strcpy(operator, stack->items[(stack->top)--]);
        status = !status;
    }
    return status;
}

bool topOperator(StackOperator *stack, char* operator){
    bool status = false;
    if (stack->top >= 0)
    {
         strcpy(operator, stack->items[(stack->top)]);
        status = !status;
    }
    return status;
}

bool StackOperatorEmpty(StackOperator *stack){
    bool status = false;
    if (stack->top == -1)
    {
        status = !status;
    }
    return status;
}

bool StackOperatorFull(StackOperator *stack){
    bool status = false;
    if (stack->top == MAX - 1)
    {
        status = !status;
    }
    return status;
}

void createStackOperand(StackOperand *stack){
    stack->top = -1;
}

bool pushOperand(StackOperand *stack, int operand){
    bool status = false;
    if (stack->top < MAX - 1)
    {
        stack->items[++(stack->top)] = operand;
        status = !status;
    }
    return status;
}

bool popOperand(StackOperand *stack, int *operand){
    bool status = false;
    if (stack->top >= 0)
    {
        *operand = stack->items[(stack->top)--];
        status = !status;
    }
    return status;
}

bool topOperand(StackOperand *stack, int *operand){
    bool status = false;
    if (stack->top >= 0)
    {
        *operand = stack->items[(stack->top)];
        status = !status;
    }
    return status;
}

bool StackOperandFull(StackOperand *stack){
    bool status = false;
    if (stack->top == MAX - 1)
    {
        status = !status;
    }
    return status;
}