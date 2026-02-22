/*
Problem: Count Nodes in Linked List
Input:
- First line: integer n
- Second line: n space-separated integers
Output:
- Print the result
Example:
Input:
5
10 20 30 40 50
Output:
10 20 30 40 50
*/

#include <stdio.h>
#include <stdlib.h>
//Structure for linked list node
struct Node
{
    int data;
    struct Node* next;
};
int main()
{
    int n;
    //Read number of nodes
    printf("Enter number of nodes: ");
    scanf("%d", &n);
    struct Node *head = NULL;
    struct Node *temp = NULL;
    struct Node *newNode = NULL;
    int value;
    //Create linked list
    printf("Enter value: ");
    for(int i = 0; i < n; i++)
    {
        newNode = (struct Node*)malloc(sizeof(struct Node));
        scanf("%d", &value);
        newNode->data = value;
        newNode->next = NULL;
        if(head == NULL)
        {
            head = newNode; //First node
        }
        else
        {
            temp->next = newNode; //Link new node
        }

        temp = newNode; //Move temp forward
    }
    //Count nodes
    int count = 0;
    temp = head;
    while(temp != NULL)
    {
        count++;
        temp = temp->next;
    }
    //Print result
    printf("%d", count);
    return 0;
}