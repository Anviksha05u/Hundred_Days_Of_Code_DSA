/*
Problem: Count Occurrences of an Element in Linked List - Implement using linked list with dynamic memory allocation.
Input:
- First line: integer n (number of nodes)
- Second line: n space-separated integers (linked list elements)
- Third line: integer key (element to be counted)
Output:
- Print the number of times the key appears in the linked list
Example:
Input:
6
10 20 30 20 40 20
20
Output:
3
Explanation:
Traverse the linked list from head to end. Each time a node's data matches the given key, increment a counter. After traversal, print the final count.
*/

/*
Problem: Count Occurrences of an Element in Linked List - Implement using linked list with dynamic memory allocation.
Input:
- First line: integer n (number of nodes)
- Second line: n space-separated integers (linked list elements)
- Third line: integer key (element to be counted)
Output:
- Print the number of times the key appears in the linked list
Example:
Input:
6
10 20 30 20 40 20
20
Output:
3
Explanation:
Traverse the linked list from head to end. Each time a node's data matches the given key, increment a counter. After traversal, print the final count.
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
//Function to count occurrences of key
int countOccurrences(struct Node* head, int key) 
{
    int count = 0; //Initialize counter
    //Traverse the list
    while (head != NULL) 
    {
        if (head->data == key) 
        {
            count++; //Increase count if match found
        }
        head = head->next; //Move to next node
    }
    return count; //Return final count
}
int main() 
{
    int n, value, key;
    struct Node *head = NULL, *tail = NULL;
    //Taking number of nodes as input
    printf("Enter number of nodes: ");
    scanf("%d", &n);
    //Taking linked list elements
    printf("Enter elements: ");
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
            tail->next = newNode; //Attach at end
            tail = newNode;
        }
    }
    //Taking key to count
    printf("Enter key to count: ");
    scanf("%d", &key);
    //Counting occurrences
    int result = countOccurrences(head, key);
    //Printing result
    printf("%d\n", result);
    return 0;
}