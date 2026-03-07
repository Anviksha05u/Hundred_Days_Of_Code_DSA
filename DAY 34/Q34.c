/*
Problem: Evaluate Postfix Expression - Implement using linked list with dynamic memory allocation.
Input:
- Postfix expression with operands and operators
Output:
- Print the integer result
Example:
Input:
2 3 1 * + 9 -
Output:
-4
Explanation:
Use stack to store operands, apply operators by popping operands, push result back. Final stack top is result.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
//Node structure for stack
struct Node
{
    int data;
    struct Node* next;
};
//Push operation
void push(struct Node** top, int value)
{
    struct Node* newNode=(struct Node*)malloc(sizeof(struct Node));
    newNode->data=value;
    newNode->next=*top;
    *top=newNode;
}
//Pop operation
int pop(struct Node** top)
{
    if (*top==NULL)
    {
        printf("Stack Underflow\n");
        return 0;
    }
    struct Node* temp=*top;
    int value=temp->data;
    *top=temp->next;
    free(temp);
    return value;
}
int main()
{
    struct Node* stack = NULL;
    char expr[100];
    printf("Enter postfix expression: ");
    fgets(expr, sizeof(expr), stdin);
    char* token=strtok(expr, " ");

    while (token!=NULL)
    {
        //If operand → push
        if (isdigit(token[0]) || 
           (token[0]=='-' && isdigit(token[1])))
        {
            push(&stack, atoi(token));
        }
        else
        {
            //Pop two operands
            int b=pop(&stack);
            int a=pop(&stack);
            int result;
            //Apply operator
            if (token[0]=='+')
                result=a + b;
            else if (token[0]=='-')
                result=a - b;
            else if (token[0]=='*')
                result=a * b;
            else if (token[0]=='/')
                result=a / b;
            //Push result
            push(&stack, result);
        }
        token=strtok(NULL, " ");
    }
    //Final result
    printf("%d\n", pop(&stack));
    return 0;
}