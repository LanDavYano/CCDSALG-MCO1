#include "evaluation.h"

int stringToInt(char *multipleDigit)
{
    return atoi(multipleDigit);
}

bool hasZeroDivision(const str256 infixExpression, Queue *postfixResult){
    str256 tokens[MAX];
    str256 token;
    StackOperator stckOprtrt;
    StackOperand stackOperand;

    createStackOperand(&stackOperand);
    createStackOperator(&stckOprtrt);
    createQueue(postfixResult);

    int tokenCount = 0;

    tokenCount = tokenizeInput(infixExpression, tokens, MAX);

    if (readInput(tokens, tokenCount, &stckOprtrt, postfixResult))
    {

        while(!queueEmpty(postfixResult)){

          if(dequeue(postfixResult, token)){
                int flagFound = false;

                //check if it is an operator
                int i = 0;
                int num_operators = sizeof(operators) / sizeof(operators[0]);
                while(i < num_operators && flagFound == false){
                    if(strcmp(operators[i],token) == 0){
                        flagFound = true;
                    }
                    i++;
                }

                //if current token is an operator
                if(flagFound == true){

                    if(strcmp(token, "!") == 0) {
                        //pop only one for ! operator
                        int operand;
                        bool pop_result = popOperand(&stackOperand, &operand);
                        
                        //if non-zero number + ! will return false
                        //if zero number + ! it will make it true
                        int curr_result = (operand == 0) ? 1 : 0;
                        pushOperand(&stackOperand, curr_result);
                        
                    }else{

                        //pop pop from the stack
                        //then evaluate if numbers in stack is 2 or more
                        //if it is then evaluate the expression then push to stack
                        int first_operand, second_operand;
                        bool first_pop = popOperand(&stackOperand, &first_operand);
                        bool second_pop = popOperand(&stackOperand, &second_operand);
                        char current_op = token[0]; 

                        //checks if there is at least two operands from operandStack
                        if(first_pop && second_pop){

                            int curr_result;

                            //ARITHMETIC OPERATORS
                            //-----------------------
                            //addition
                            if(strcmp(token, "+") == 0) {
                                curr_result = second_operand + first_operand;
                            }

                            //subtraction
                            else if(strcmp(token, "-") == 0) {
                                curr_result = second_operand - first_operand;
                            }

                            //multiplication
                            else if(strcmp(token, "*") == 0) {
                                curr_result = second_operand * first_operand;
                            }
                            //division
                            else if(strcmp(token, "/") == 0) {
                                if(first_operand == 0) {
                                    return true;
                                }
                                curr_result = second_operand / first_operand;
                            }
                            //modulo
                            else if(strcmp(token, "%") == 0) {
                                curr_result = second_operand % first_operand ;
                            }
                            //power
                            else if(strcmp(token, "^") == 0) {
                                curr_result = (int)(round(pow(second_operand, first_operand)));
                            }

                            //RELATIONAL OPERATORS
                            //-----------------------
                            //greater than or equal to 
                            else if(strcmp(token, ">=") == 0) {
                                curr_result = (second_operand >= first_operand) ? 1 : 0;
                            }
                            //less than or qual to 
                            else if(strcmp(token, "<=") == 0) {
                                curr_result = (second_operand <= first_operand) ? 1 : 0;
                            }
                            //greater than
                            else if(strcmp(token, ">") == 0) {
                                curr_result = (second_operand > first_operand) ? 1 : 0;
                            }
                            //less than
                            else if(strcmp(token, "<") == 0) {
                                curr_result = (second_operand < first_operand) ? 1 : 0;
                            }
                            //not equals
                            else if(strcmp(token, "!=") == 0) {
                                curr_result = (first_operand != second_operand);
                            }
                            //equals
                            else if(strcmp(token, "==") == 0) {
                                curr_result = (first_operand == second_operand);
                            }

                            //LOGICAL OPERATORS
                            //----------------
                            else if(strcmp(token, "&&") == 0) {
                                curr_result = (second_operand && first_operand) ? 1 : 0;
                            }
                            else if(strcmp(token, "||") == 0) {
                                curr_result = (second_operand || first_operand) ? 1 : 0;
                            }

                            //if there is an error
                            else {
                                printf("Unsupported operator: %s\n", token);
                            }

                            //push evaluated expression to stack
                            pushOperand(&stackOperand,curr_result);
                        }
                    }

                }else{

                    //push operand to stack
                    int push_num = stringToInt(token);
                    pushOperand(&stackOperand, push_num);
                }


            }
        }

        return false;
    }
}



int runPostfixtoEvaluation(const str256 infixExpression, Queue *postfixResult){
    str256 tokens[MAX];
    str256 token;
    StackOperator stckOprtrt;
    StackOperand stackOperand;

    createStackOperand(&stackOperand);
    createStackOperator(&stckOprtrt);
    createQueue(postfixResult);

    int tokenCount = 0;

    tokenCount = tokenizeInput(infixExpression, tokens, MAX);

    if (readInput(tokens, tokenCount, &stckOprtrt, postfixResult))
    {

        while(!queueEmpty(postfixResult)){

            if(dequeue(postfixResult, token)){

                int flagFound = false;

                //check if it is an operator
                int i = 0;
                int num_operators = sizeof(operators) / sizeof(operators[0]);
                while(i < num_operators && flagFound == false){
                    if(strcmp(operators[i],token) == 0){
                        flagFound = true;
                    }
                    i++;
                }

                if(flagFound == true){

                    if(strcmp(token, "!") == 0) {
                        //pop only one for ! operator
                        int operand;
                        bool pop_result = popOperand(&stackOperand, &operand);
                        
                        if(pop_result) {
                            //if non-zero number + ! will return false
                            //if zero number + ! it will make it true
                            int curr_result = (operand == 0) ? 1 : 0;
                            pushOperand(&stackOperand, curr_result);
                        } else {
                            printf("Error: Not enough operands for !\n");
                            return -1;
                        }
                    }else{

                        //pop pop from the stack
                        //then evaluate if numbers in stack is 2 or more
                        //if it is then evaluate the expression then push to stack
                        int first_operand, second_operand;
                        bool first_pop = popOperand(&stackOperand, &first_operand);
                        bool second_pop = popOperand(&stackOperand, &second_operand);
                        char current_op = token[0]; 

                        //checks if there is at least two operands from operandStack
                        if(first_pop && second_pop){

                            int curr_result;

                            //ARITHMETIC OPERATORS
                            //-----------------------
                            //addition
                            if(strcmp(token, "+") == 0) {
                                curr_result = second_operand + first_operand;
                            }

                            //subtraction
                            else if(strcmp(token, "-") == 0) {
                                curr_result = second_operand - first_operand;
                            }

                            //multiplication
                            else if(strcmp(token, "*") == 0) {
                                curr_result = second_operand * first_operand;
                            }
                            //division
                            else if(strcmp(token, "/") == 0) {
                                if(first_operand == 0) {
                                    return -1;
                                }
                                curr_result = second_operand / first_operand;
                            }
                            //modulo
                            else if(strcmp(token, "%") == 0) {
                                curr_result = second_operand % first_operand ;
                            }
                            //power
                            else if(strcmp(token, "^") == 0) {
                                curr_result = (int)(round(pow(second_operand, first_operand)));
                            }

                            //RELATIONAL OPERATORS
                            //-----------------------
                            //greater than or equal to 
                            else if(strcmp(token, ">=") == 0) {
                                curr_result = (second_operand >= first_operand) ? 1 : 0;
                            }
                            //less than or qual to 
                            else if(strcmp(token, "<=") == 0) {
                                curr_result = (second_operand <= first_operand) ? 1 : 0;
                            }
                            //greater than
                            else if(strcmp(token, ">") == 0) {
                                curr_result = (second_operand > first_operand) ? 1 : 0;
                            }
                            //less than
                            else if(strcmp(token, "<") == 0) {
                                curr_result = (second_operand < first_operand) ? 1 : 0;
                            }
                            //not equals
                            else if(strcmp(token, "!=") == 0) {
                                curr_result = (first_operand != second_operand);
                            }
                            //equals
                            else if(strcmp(token, "==") == 0) {
                                curr_result = (first_operand == second_operand);
                            }

                            //LOGICAL OPERATORS
                            //----------------
                            else if(strcmp(token, "&&") == 0) {
                                curr_result = (second_operand && first_operand) ? 1 : 0;
                            }
                            else if(strcmp(token, "||") == 0) {
                                curr_result = (second_operand || first_operand) ? 1 : 0;
                            }
                            //if there is an error
                            else {
                                printf("Unsupported operator: %s\n", token);
                            }

                            //push evaluated expression to stack
                            pushOperand(&stackOperand,curr_result);
                        }
                    }

                }else{
                    //push to stack
                    int push_num = stringToInt(token);
                    pushOperand(&stackOperand, push_num);
                }

            }
        }

        // After processing all tokens

        int final_result;
        if(popOperand(&stackOperand, &final_result)) {
            return final_result;  // Return the result
        }


 
        return -1;
    }

}