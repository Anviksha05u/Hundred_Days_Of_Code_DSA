/*
Problem: Doubly Linked List Insertion and Traversal - Implement using linked list with dynamic memory allocation.
Input:
- First line: integer n
- Second line: n space-separated integers
Output:
- Print the linked list elements in forward order, space-separated
Example:
Input:
5
10 20 30 40 50
Output:
10 20 30 40 50
Explanation:
Each node has data, next, prev. Insert nodes sequentially, traverse from head using next pointer.
*/

#include <stdio.h>
#include <stdlib.h>

//Structure for Doubly Linked List node
struct Node
{
    int data;
    struct Node* next;
    struct Node* prev;
};
//Function to create a new node
struct Node* createNode(int data)
{
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    newNode->prev = NULL;
    return newNode;
}
//Function to print list in forward direction
void printList(struct Node* head)
{
    while (head != NULL)
    {
        printf("%d", head->data);
        if (head->next != NULL)
            printf(" ");
        head = head->next;
    }
}
int main()
{
    int n, value;
    struct Node *head = NULL, *tail = NULL;
    //Read number of nodes
    printf("Ente number of nodes: ");
    scanf("%d", &n);
    //Insert nodes sequentially
    printf("Ente value: ");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &value);
        struct Node* newNode = createNode(value);
        if (head == NULL)
        {
            head = tail = newNode; //First node
        }
        else
        {
            tail->next = newNode; //Connect next
            newNode->prev = tail; //Connect previous
            tail = newNode; //Move tail forward
        }
    }
    //Traverse in forward direction
    printList(head);
    return 0;
}