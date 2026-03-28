/*
Problem Statement:
Print the nodes visible when the binary tree is viewed from the right side.
Input Format:
- First line contains integer N
- Second line contains level-order traversal (-1 indicates NULL)
Output Format:
- Print right view nodes
Example:
Input:
7
1 2 3 4 5 -1 6
Output:
1 3 6
Explanation:
At each level, the rightmost node is visible from the right view.
*/

#include <stdio.h>
#include <stdlib.h>
//Tree node
struct Node
{
    int data;
    struct Node *left, *right;
};
//Create new node
struct Node* createNode(int val)
{
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = val;
    node->left = node->right = NULL;
    return node;
}
//Build tree from level order
struct Node* buildTree(int arr[], int n)
{
    if(n == 0 || arr[0] == -1)
        return NULL;
    struct Node* root = createNode(arr[0]);
    struct Node* queue[n];
    int front = 0, rear = 0;
    queue[rear++] = root;
    int i = 1;
    while(i < n)
    {
        struct Node* curr = queue[front++];
        //Left child
        if(arr[i] != -1)
        {
            curr->left = createNode(arr[i]);
            queue[rear++] = curr->left;
        }
        i++;
        //Right child
        if(i < n && arr[i] != -1)
        {
            curr->right = createNode(arr[i]);
            queue[rear++] = curr->right;
        }
        i++;
    }
    return root;
}
//Right View Function
void rightView(struct Node* root)
{
    if(root == NULL) return;
    struct Node* queue[1000];
    int front = 0, rear = 0;
    queue[rear++] = root;
    while(front < rear)
    {
        int size = rear - front;
        for(int i = 0; i < size; i++)
        {
            struct Node* curr = queue[front++];
            //Print last node of each level
            if(i == size - 1)
                printf("%d ", curr->data);
            if(curr->left)
                queue[rear++] = curr->left;
            if(curr->right)
                queue[rear++] = curr->right;
        }
    }
}
int main()
{
    int n;
    printf("Enter number of nodes: ");
    scanf("%d", &n);
    int arr[n];
    printf("Enter level order (-1 for NULL): ");
    for(int i = 0; i < n; i++)
        scanf("%d", &arr[i]);
    struct Node* root = buildTree(arr, n);
    printf("Right View: ");
    rightView(root);
    return 0;
}