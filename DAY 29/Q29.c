/*
Problem: Rotate Linked List Right by k Places - Implement using linked list with dynamic memory allocation.
Input:
- First line: integer n
- Second line: n space-separated integers
- Third line: integer k
Output:
- Print the linked list elements after rotation, space-separated
Example:
Input:
5
10 20 30 40 50
2
Output:
40 50 10 20 30
Explanation:
Connect last node to head forming circular list. Traverse to (n-k)th node, set next to NULL, update head to (n-k+1)th node.
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
//Function to get length
int getLength(struct Node* head)
{
    int count=0;
    while (head!=NULL)
    {
        count++;
        head=head->next;
    }
    return count;
}
//Rotate list by k places
struct Node* rotateRight(struct Node* head, int k)
{
    if (head==NULL || head->next==NULL || k==0)
        return head;
    int n=getLength(head);
    k=k%n; //Handle k>n
    if (k==0)
        return head;
    struct Node* temp=head;
    //Go to last node
    while (temp->next!=NULL)
        temp=temp->next;
    temp->next=head; //Make circular
    //Move to (n - k)th node
    int steps=n-k;
    temp=head;
    for (int i=1; i<steps; i++)
        temp=temp->next;
    head=temp->next; //New head
    temp->next=NULL; //Break circle
    return head;
}
//Print list
void printList(struct Node* head)
{
    while (head!=NULL)
    {
        printf("%d ", head->data);
        head=head->next;
    }
}
int main()
{
    int n, value, k;
    struct Node *head=NULL, *tail=NULL;
    //Input size
    printf("Enter the size: ");
    scanf("%d", &n);
    //Create list
    printf("Enter value: ");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &value);
        struct Node* newNode=createNode(value);
        if (head==NULL)
            head=tail=newNode;
        else
        {
            tail->next=newNode;
            tail=newNode;
        }
    }
    //Input k
    printf("Enter value of k: ");
    scanf("%d", &k);
    //Rotate list
    head=rotateRight(head, k);
    //Print result
    printList(head);
    return 0;
}