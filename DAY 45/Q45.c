/*
Problem Statement:
Find the height (maximum depth) of a given binary tree.
Input Format:
- First line contains integer N
- Second line contains level-order traversal (-1 represents NULL)
Output Format:
- Print the height of the tree
Example:
Input:
7
1 2 3 4 5 -1 -1
Output:
3
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
int height(struct Node* root)
{
    if(root == NULL)
        return 0;
    int leftH = height(root->left);
    int rightH = height(root->right);
    return (leftH > rightH ? leftH : rightH) + 1;
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
    if(arr[0] == -1) {
        printf("0");
        return 0;
    }
    struct Node* root = createNode(arr[0]);
    struct Node* queue[n];
    int front = 0, rear = 0;
    queue[rear++] = root;
    int i = 1;
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
    printf("%d", height(root));
    return 0;
}