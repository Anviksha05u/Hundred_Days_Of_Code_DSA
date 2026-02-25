/*
Problem: Delete First Occurrence of a Key - Implement using linked list with dynamic memory allocation.
Input:
- First line: integer n
- Second line: n space-separated integers
- Third line: integer key
Output:
- Print the linked list elements after deletion, space-separated
Example:
Input:
5
10 20 30 40 50
30
Output:
10 20 40 50
Explanation:
Traverse list, find first node with key, remove it by adjusting previous node's next pointer.
*/

#include <stdio.h>
#include <stdlib.h>
//Structure definition for linked list node
struct Node 
{
    int data;
    struct Node* next;
};
//Function to create a new node
struct Node* createNode(int data) 
{
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}
//Function to delete first occurrence of key
struct Node* deleteKey(struct Node* head, int key) 
{
    //If list is empty
    if (head == NULL)
        return head;
    struct Node *temp = head, *prev = NULL;
    //If head node itself contains the key
    if (temp->data == key) 
    {
        head = temp->next; //Move head to next node
        free(temp); //Free memory of deleted node
        return head;
    }
    //Search for key in rest of the list
    while (temp != NULL && temp->data != key) 
    {
        prev = temp;
        temp = temp->next;
    }
    //If key not found
    if (temp == NULL)
        return head;
    //Adjust previous node's next pointer
    prev->next = temp->next;
    //Free memory of deleted node
    free(temp);
    return head;
}
//Function to print linked list
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
    int n, value, key;
    struct Node *head = NULL, *tail = NULL;
    //Read number of elements
    printf("Enter number of elements: ");
    scanf("%d", &n);
    //Create linked list
    printf("Enter values: ");
    for (int i = 0; i < n; i++) 
    {
        scanf("%d", &value);
        struct Node* newNode = createNode(value);
        if (head == NULL) 
        {
            head = tail = newNode;
        } 
        else 
        {
            tail->next = newNode;
            tail = newNode;
        }
    }
    //Read key to delete
    printf("Enter key to delete: ");
    scanf("%d", &key);
    //Delete first occurrence
    head = deleteKey(head, key);
    //Print updated list
    printList(head);
    return 0;
}