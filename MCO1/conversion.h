#ifndef CONVERSION_H
#define CONVERSION_H
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>
#include "stack.h"
#include "queue.h"

// In conversion.h
extern const str256 operators[257];
typedef char str256[257];

bool isOperator(str256 token);
bool isOperand(str256 token);
int getPrecedence(str256 operator);
bool isLeftAssociative(str256 operator);
int getNextToken(const char* input, int startPos, str256 token);
int tokenizeInput(const char* input, str256 tokens[], int maxTokens);
bool shouldPop(str256 oprtrFrmStck, str256 crntOprtr);
bool readInput(str256 tokens[], int tokenCount, StackOperator *stckOprtrt, Queue *outputQueue);
bool runInfixToPostfix(const str256 infixExpression, Queue *postfixResult);

#endif
