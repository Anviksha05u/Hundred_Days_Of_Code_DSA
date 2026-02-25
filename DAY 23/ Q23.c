/*
Problem: Merge Two Sorted Linked Lists - Implement using linked list with dynamic memory allocation.
Input:
- First line: integer n
- Second line: n space-separated integers (first list)
- Third line: integer m
- Fourth line: m space-separated integers (second list)
Output:
- Print the merged linked list elements, space-separated
Example:
Input:
5
10 20 30 40 50
4
15 25 35 45
Output:
10 15 20 25 30 35 40 45 50
Explanation:
Compare nodes of both lists, append smaller to result, continue until all nodes are merged.
*/

#include <stdio.h>
#include <stdlib.h>
//Structure definition for a linked list node
struct Node 
{
    int data; //Stores the value of the node
    struct Node* next; //Pointer to the next node
};
//Function to create a new node with given data
struct Node* createNode(int data) 
{
    //Allocate memory dynamically for new node
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data; //Assign data
    newNode->next = NULL; //Initialize next as NULL
    return newNode; //Return created node
}
//Function to merge two sorted linked lists
struct Node* mergeSortedLists(struct Node* l1, struct Node* l2) 
{
    //Dummy node helps simplify merging logic
    struct Node dummy;
    struct Node* tail = &dummy; //Tail pointer to build merged list
    dummy.next = NULL; //Initially merged list is empty
    //Compare nodes from both lists until one becomes NULL
    while (l1 != NULL && l2 != NULL) 
    {
        if (l1->data <= l2->data) 
        {
            //Attach smaller node to merged list
            tail->next = l1;
            l1 = l1->next; //Move l1 forward
        } 
        else 
        {
            tail->next = l2;
            l2 = l2->next; //Move l2 forward
        }
    
        tail = tail->next; //Move tail forward
    }
    //Attach remaining nodes (if any)
    tail->next = (l1 != NULL) ? l1 : l2;
    //Return head of merged list (skip dummy node)
    return dummy.next;
}
//Function to print the linked list
void printList(struct Node* head) 
{
    while (head != NULL) 
    {
        printf("%d", head->data); //Print current node
        //Print space only if not last element
        if (head->next != NULL) 
            printf(" ");
        head = head->next; //Move to next node
    }
    printf("\n");
}
int main() 
{
    int n, m, value;
    //Pointers for first and second list
    struct Node *list1 = NULL, *list2 = NULL;
    struct Node *tail1 = NULL, *tail2 = NULL;
    //Read number of elements for first list
    printf("Enter number of elements for first list: ");
    scanf("%d", &n);
    //Create first sorted linked list
    printf("Enter values: ");
    for (int i = 0; i < n; i++) 
    {
        scanf("%d", &value);
        struct Node* newNode = createNode(value);
        if (list1 == NULL) 
        {
            //First node becomes head
            list1 = tail1 = newNode;
        } 
        else 
        {
            //Attach new node at the end
            tail1->next = newNode;
            tail1 = newNode;
        }
    }
    //Read number of elements for second list
    printf("Enter number of elements for second list: ");
    scanf("%d", &m);
    //Create second sorted linked list
    printf("Enter values: ");
    for (int i = 0; i < m; i++) 
    {
        scanf("%d", &value);
        struct Node* newNode = createNode(value);
        if (list2 == NULL) 
        {
            list2 = tail2 = newNode;
        } 
        else 
        {
            tail2->next = newNode;
            tail2 = newNode;
        }
    }
    //Merge both sorted lists
    struct Node* merged = mergeSortedLists(list1, list2);
    //Print merged list
    printList(merged);
    return 0;
}