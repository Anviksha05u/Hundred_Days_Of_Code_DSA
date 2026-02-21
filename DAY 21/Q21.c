/*
Problem: Create and Traverse Singly Linked List
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
//Structure for a node
struct Node
{
    int data; //Stores value
    struct Node* next; //Pointer to next node
};
int main()
{
    int n;
    //Read number of nodes
    printf("Enter number of nodes: ");
    scanf("%d", &n);
    struct Node *head = NULL; //Head pointer
    struct Node *temp = NULL; //Temporary pointer
    struct Node *newNode = NULL;
    int value;
    //Create linked list
    printf("Enter value: ");
    for(int i = 0; i < n; i++)
    {
        //Allocate memory for new node
        newNode = (struct Node*)malloc(sizeof(struct Node));
        //Read value
        scanf("%d", &value);
        newNode->data = value; //Store data
        newNode->next = NULL; //Last node points to NULL
        if(head == NULL)
        {
            //First node becomes head
            head = newNode;
        }
        else
        {
            //Attach new node at the end
            temp->next = newNode;
        }
        temp = newNode; //Move temp to last node
    }
    //Traverse and print linked list
    temp = head;
    while(temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    return 0;
}