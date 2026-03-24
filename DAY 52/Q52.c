/*
Problem Statement:
Find the Lowest Common Ancestor (LCA) of two nodes in a Binary Tree.
Input Format:
- First line contains integer N
- Second line contains level-order traversal (-1 represents NULL)
- Third line contains two node values
Output Format:
- Print the LCA value
Example:
Input:
7
1 2 3 4 5 6 7
4 5
Output:
2
*/

#include <stdio.h>
#include <stdlib.h>
//Tree node
struct Node 
{
    int data;
    struct Node *left, *right;
};
//Create node
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
        //left child
        if(arr[i] != -1)
        {
            curr->left = createNode(arr[i]);
            queue[rear++] = curr->left;
        }
        i++;
        //right child
        if(i < n && arr[i] != -1) 
        {
            curr->right = createNode(arr[i]);
            queue[rear++] = curr->right;
        }
        i++;
    }
    return root;
}
//Find LCA
struct Node* findLCA(struct Node* root, int n1, int n2)
{
    if(root == NULL)
        return NULL;
    if(root->data == n1 || root->data == n2)
        return root;
    struct Node* left = findLCA(root->left, n1, n2);
    struct Node* right = findLCA(root->right, n1, n2);
    if(left != NULL && right != NULL)
        return root;
    if(left != NULL)
        return left;
    else
        return right;
}
int main()
{
    int n, n1, n2;
    printf("Enter number of nodes: ");
    scanf("%d", &n);
    int arr[n];
    printf("Enter level order (-1 for NULL): ");
    for(int i = 0; i < n; i++)
        scanf("%d", &arr[i]);
    struct Node* root = buildTree(arr, n);
    printf("Enter two node values: ");
    scanf("%d %d", &n1, &n2);
    struct Node* lca = findLCA(root, n1, n2);
    if(lca != NULL)
        printf("LCA: %d\n", lca->data);
    else
        printf("LCA not found\n");
    return 0;
}