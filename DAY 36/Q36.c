/*
Problem: Circular Queue Using Array - Implement using linked list with dynamic memory allocation.
Input:
- First line: integer n (number of elements to enqueue)
- Second line: n space-separated integers
- Third line: integer m (number of dequeue operations)Output:
- Print queue elements from front to rear after operations, space-separated
Example:
Input:
5
10 20 30 40 50
2
Output:
30 40 50 10 20
Explanation:
Use array and front/rear pointers. Rear wraps around to start after reaching array end. Dequeue removes elements from front. Display remaining elements in correct order.
*/

#include <stdio.h>
#define MAX 100
int queue[MAX];
int front=-1, rear=-1;
//Enqueue operation
void enqueue(int value)
{
    if ((rear+1)%MAX==front) //Queue full
    {
        printf("Queue Overflow\n");
        return;
    }
    if (front==-1) //First element
        front=0;
    rear=(rear+1)%MAX;
    queue[rear]=value;
}
//Dequeue operation
void dequeue()
{
    if (front==-1) //Empty
        return;
    if (front==rear) //Only one element
    {
        front=rear=-1;
    }
    else
    {
        front=(front+1)%MAX;
    }
}
//Display queue
void display()
{
    if (front==-1)
        return;
    int i=front;
    while (1)
    {
        printf("%d", queue[i]);
        if (i==rear)
            break;
        printf(" ");
        i=(i+1)%MAX;
    }
}
int main()
{
    int n, m, x;
    printf("Enter number of elements to enqueue: ");
    scanf("%d", &n);
    printf("Enter value: ");
    for (int i=0; i<n; i++)
    {
        scanf("%d", &x);
        enqueue(x);
    }
    printf("Enter number of dequeue operations: ");
    scanf("%d", &m);
    for (int i=0; i<m; i++)
    {
        int temp = queue[front]; //Store front element
        dequeue(); //Remove it
        enqueue(temp); //Insert at rear
    }
    display();
    return 0;
}