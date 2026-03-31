/*
Problem Statement:
Construct a binary tree from given inorder and postorder traversal arrays.
Input Format:
- First line contains integer N
- Second line contains inorder traversal
- Third line contains postorder traversal
Output Format:
- Print preorder traversal of constructed tree
Example:
Input:
5
4 2 5 1 3
4 5 2 3 1
Output:
1 2 4 5 3
Explanation:
Postorder gives root at end, inorder divides left and right subtrees.
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
//Find index in inorder
int findIndex(int inorder[], int start, int end, int val)
{
    for(int i = start; i <= end; i++)
    {
        if(inorder[i] == val)
            return i;
    }
    return -1;
}
//Build tree
struct Node* buildTree(int inorder[], int postorder[], int start, int end, int* postIndex)
{
    if(start > end)
        return NULL;
    //Pick root from postorder
    int val = postorder[*postIndex];
    (*postIndex)--;
    struct Node* root = createNode(val);
    //If leaf node
    if(start == end)
        return root;
    int index = findIndex(inorder, start, end, val);
    //Build RIGHT first (important!)
    root->right = buildTree(inorder, postorder, index + 1, end, postIndex);
    root->left  = buildTree(inorder, postorder, start, index - 1, postIndex);

    return root;
}
//Preorder traversal
void preorder(struct Node* root)
{
    if(root == NULL)
        return;
    printf("%d ", root->data);
    preorder(root->left);
    preorder(root->right);
}
int main()
{
    int n;
    printf("Enter number of nodes: ");
    scanf("%d", &n);
    int inorder[n], postorder[n];
    printf("Enter inorder: ");
    for(int i = 0; i < n; i++)
        scanf("%d", &inorder[i]);
    printf("Enter postorder: ");
    for(int i = 0; i < n; i++)
        scanf("%d", &postorder[i]);
    int postIndex = n - 1;
    struct Node* root = buildTree(inorder, postorder, 0, n - 1, &postIndex);
    printf("Preorder: ");
    preorder(root);
    return 0;
}