#ifndef EVALUATION_H
#define EVALUATION_H
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <math.h>
#include "queue.h"
#include "stack.h"
#include "conversion.h"

int stringToInt(char *multipleDigit);
bool hasZeroDivision(const str256 infixExpression, Queue *postfixResult);
int runPostfixtoEvaluation(const str256 infixExpression, Queue *postfixResult);

#endif