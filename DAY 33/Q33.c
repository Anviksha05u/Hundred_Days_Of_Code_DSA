/*
Problem: Convert an infix expression to postfix notation using stack.
Input:
- Single line: infix expression (operands are single characters)
Output:
- Print the postfix expression
Example:
Input:
A+B*C
Output:
ABC*+
Explanation:
Operator precedence: * > +
Use stack to handle operator precedence and associativity
*/

#include <stdio.h>
#include <ctype.h> //For isalnum()
#define MAX 100
char stack[MAX];
int top=-1;
//Push operator to stack
void push(char c)
{
    stack[++top]=c;
}
//Pop operator from stack
char pop()
{
    return stack[top--];
}
//Check precedence of operators
int precedence(char op)
{
    if (op=='+' || op=='-') 
    return 1;
    if (op=='*' || op=='/') 
    return 2;
    if (op=='^') 
    return 3;
    return 0;
}
int main()
{
    char infix[MAX], postfix[MAX];
    int i, j=0;
    printf("Enter infix expression: ");
    scanf("%s", infix);
    for (i=0; infix[i]!='\0'; i++)
    {
        char c=infix[i];
        //If operand, add to postfix
        if (isalnum(c))
        {
            postfix[j++]=c;
        }
        //If '(' push to stack
        else if (c=='(')
        {
            push(c);
        }
        //If ')', pop until '('
        else if (c==')')
        {
            while (top!=-1 && stack[top]!='(')
                postfix[j++]=pop();
            pop(); //Remove '('
        }
        //Operator case
        else
        {
            while (top!=-1 && precedence(stack[top])>=precedence(c))
                postfix[j++]=pop();
            push(c);
        }
    }
    //Pop remaining operators
    while (top!=-1)
        postfix[j++]=pop();
    postfix[j]='\0';
    printf("Postfix expression: %s", postfix);
    return 0;
}