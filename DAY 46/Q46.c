/*
Problem: Level Order Traversal
Implement the solution for this problem.
Input:
- Input specifications
Output:
- Output specifications
*/

#include <stdio.h>
#include <stdlib.h>
struct Node 
{
    int data;
    struct Node *left, *right;
};
struct Node* createNode(int val)
{
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = val;
    newNode->left = newNode->right = NULL;
    return newNode;
}
void levelOrder(struct Node* root)
{
    if(root == NULL) return;
    struct Node* queue[1000];
    int front = 0, rear = 0;
    queue[rear++] = root;
    while(front < rear)
    {
        struct Node* curr = queue[front++];
        printf("%d ", curr->data);
        if(curr->left)
            queue[rear++] = curr->left;
        if(curr->right)
            queue[rear++] = curr->right;
    }
}
int main()
{
    int n;
    printf("Enter number of elements: ");
    scanf("%d", &n);
    int arr[n];
    printf("Enter elements: ");
    for(int i = 0; i < n; i++)
        scanf("%d", &arr[i]);
    if(arr[0] == -1) return 0;
    struct Node* root = createNode(arr[0]);
    struct Node* queue[1000];
    int front = 0, rear = 0;
    queue[rear++] = root;
    int i = 1;
    //Build tree
    while(i < n)
    {
        struct Node* curr = queue[front++];
        if(arr[i] != -1)
        {
            curr->left = createNode(arr[i]);
            queue[rear++] = curr->left;
        }
        i++;
        if(i < n && arr[i] != -1)
        {
            curr->right = createNode(arr[i]);
            queue[rear++] = curr->right;
        }
        i++;
    }
    //Level order traversal
    levelOrder(root);
    return 0;
}