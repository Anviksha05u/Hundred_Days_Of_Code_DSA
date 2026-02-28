/*
Problem: Circular Linked List Creation and Traversal - Implement using linked list with dynamic memory allocation.
Input:
- First line: integer n
- Second line: n space-separated integers
Output:
- Print the circular linked list elements starting from head, space-separated
Example:
Input:
5
10 20 30 40 50
Output:
10 20 30 40 50
Explanation:
Last node's next points to head. Traverse from head until returning to head to avoid infinite loop.
*/

#include <stdio.h>
#include <stdlib.h>
//Structure for node
struct Node
{
    int data;
    struct Node* next;
};
//Create new node
struct Node* createNode(int data)
{
    struct Node* newNode=(struct Node*)malloc(sizeof(struct Node));
    newNode->data=data;
    newNode->next=NULL;
    return newNode;
}
int main()
{
    int n, value;
    struct Node *head=NULL, *tail=NULL;
    //Read number of nodes
    printf("Enter number of nodes: ");
    scanf("%d", &n);
    //Create circular linked list
    printf("Enter value: ");
    for (int i=0; i<n; i++)
    {
        scanf("%d", &value);
        struct Node* newNode=createNode(value);
        if (head==NULL)
        {
            head=tail=newNode; //First node
        }
        else
        {
            tail->next = newNode; //Link next
            tail = newNode; //Move tail
        }
    }
    //Make it circular
    if (tail!=NULL)
        tail->next=head;
    //Traverse and print
    if (head!=NULL)
    {
        struct Node* temp=head;
        do
        {
            printf("%d ", temp->data);
            temp = temp->next;
        }
        while (temp != head); //Stop when back to head
    }
    return 0;
}