/*
Problem: Implement a stack data structure using an array with the following operations: push, pop, and display.
Input:
- First line: integer n (number of operations)
- Next n lines: operation type and value (if applicable)
  - 1 value: push value
  - 2: pop
  - 3: display
Output:
- For display: print stack elements from top to bottom
- For pop: print popped element or 'Stack Underflow'
Example:
Input:
5
1 10
1 20
3
2
3
Output:
20 10
20
10
*/

#include <stdio.h>
#define MAX 100
int stack[MAX];
int top=-1;
//Function to push element into stack
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
//Function to pop element from stack
void pop() 
{
    if (top==-1) 
    {
        printf("Stack Underflow\n");
    } 
    else 
    {
        printf("%d\n", stack[top]);
        top--;
    }
}
//Function to display stack elements from top to bottom
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
  int n;
  printf("Enter number of operations: ");
  scanf("%d", &n); //Number of operations
  for (int i=0; i<n; i++) 
  {
    int op, val;
    printf("Enter operation: ");
    scanf("%d", &op);
    if (op==1) //Push operation
    {
      printf("Enter value: ");
      scanf("%d", &val);
      push(val); 
    } 
    else if (op==2) //Pop operation
    {   
      pop(); 
    } 
    else if (op==3) //Display
    {   
      display(); 
    }
  }
  return 0;
}