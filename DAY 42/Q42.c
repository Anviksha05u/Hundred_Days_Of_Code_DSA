/*
Problem Statement:
Given a queue of integers, reverse the queue using a stack.
Input Format:
- First line contains integer N
- Second line contains N space-separated integers
Output Format:
- Print the reversed queue
Example:
Input:
5
10 20 30 40 50
Output:
50 40 30 20 10
*/

#include <stdio.h>
int main()
{
    int n;
    printf("Enter number of elements: ");
    scanf("%d",&n);
    int queue[n];
    int stack[n];
    int top = -1;
    printf("Enter elements: ");
    for(int i=0;i<n;i++)
        scanf("%d",&queue[i]);
    //Push queue elements into stack
    for(int i=0;i<n;i++)
        stack[++top] = queue[i];
    //Pop stack back into queue
    for(int i=0;i<n;i++)
        queue[i] = stack[top--];
    //Print reversed queue
    for(int i=0;i<n;i++)
        printf("%d ",queue[i]);
    return 0;
}