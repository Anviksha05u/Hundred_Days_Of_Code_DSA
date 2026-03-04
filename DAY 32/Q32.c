/*
Problem: Implement push and pop operations on a stack and verify stack operations.
Input:
- First line: integer n
- Second line: n integers to push
- Third line: integer m (number of pops)
Output:
- Print remaining stack elements from top to bottom
Example:
Input:
5
10 20 30 40 50
2
Output:
30 20 10
*/

#include <stdio.h>
#define MAX 100
int stack[MAX];
int top=-1;
//Function to push value onto stack
void push(int val) 
{
    if (top==MAX - 1) 
    {
        printf("Stack Overflow\n");
    } 
    else 
    {
        top++;
        stack[top]=val;
    }
}
//Function to pop top value from stack
void pop() 
{
    if (top==-1) 
    {
        printf("Stack Underflow\n");
    } 
    else 
    {
        top--;
    }
}
//Function to display stack from top to bottom
void display() 
{
    if (top==-1) 
    {
        printf("Stack is empty\n");
    } 
    else 
    {
        for (int i=top; i>=0; i--) 
        {
            printf("%d", stack[i]);
            if (i!=0) printf(" ");
        }
        printf("\n");
    }
}
int main() 
{
    int n, m, val;
    printf("Enter number of elements to push: ");
    scanf("%d", &n); //Number of elements to push
    printf("Enter value: ");
    for (int i=0; i<n; i++) 
    {
        scanf("%d", &val);
        push(val);
    }
    printf("Enter number of pops: ");
    scanf("%d", &m); //Number of pops
    for (int i=0; i<m; i++) 
    {
        pop();
    }
    display(); //Print remaining elements
    return 0;
}