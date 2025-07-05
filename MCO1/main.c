#include <stdio.h>
#include "conversion.h"
#include "evaluation.h"

int main()
{
    str256 userInput = "", token = "";
    Queue postfixQueue;

    while(scanf("%s", userInput) == 1){
        if (strcmp("QUIT", userInput) == 0){
            break;
        }
        else if (runInfixToPostfix(userInput, &postfixQueue)){
            while (!queueEmpty(&postfixQueue)){
                dequeue(&postfixQueue, token);
                printf("%s ", token);
            }
            if(!(hasZeroDivision(userInput, &postfixQueue))){
                int result = runPostfixtoEvaluation(userInput, &postfixQueue);
                if(result != -1) {
                    printf("\n%d\n", result);
                } else {
                    printf("\nError in evaluation\n");
                }
            }else{
                printf("\nDivision by zero error!\n");
            }
        }
    }
    
    return 0;
}