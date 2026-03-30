/*
Problem Statement:
Construct a binary tree from given preorder and inorder traversal arrays.
Input Format:
- First line contains integer N
- Second line contains preorder traversal
- Third line contains inorder traversal
Output Format:
- Print postorder traversal of constructed tree
Example:
Input:
5
1 2 4 5 3
4 2 5 1 3
Output:
4 5 2 3 1
Explanation:
Preorder identifies root, inorder splits left and right subtrees.
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
    for(int i = start; i <= end; i++) {
        if(inorder[i] == val)
            return i;
    }
    return -1;
}
//Build tree
struct Node* buildTree(int preorder[], int inorder[], int start, int end, int* preIndex)
{

    if(start > end)
        return NULL;
    //Pick root from preorder
    int val = preorder[*preIndex];
    (*preIndex)++;
    struct Node* root = createNode(val);
    //If leaf node
    if(start == end)
        return root;
    int index = findIndex(inorder, start, end, val);
    //Build left and right
    root->left = buildTree(preorder, inorder, start, index - 1, preIndex);
    root->right = buildTree(preorder, inorder, index + 1, end, preIndex);
    return root;
}
//Postorder traversal
void postorder(struct Node* root)
{
    if(root == NULL)
        return;
    postorder(root->left);
    postorder(root->right);
    printf("%d ", root->data);
}
int main()
{
    int n;
    printf("Enter number of nodes: ");
    scanf("%d", &n);
    int preorder[n], inorder[n];
    printf("Enter preorder: ");
    for(int i = 0; i < n; i++)
        scanf("%d", &preorder[i]);
    printf("Enter inorder: ");
    for(int i = 0; i < n; i++)
        scanf("%d", &inorder[i]);
    int preIndex = 0;
    struct Node* root = buildTree(preorder, inorder, 0, n - 1, &preIndex);
    printf("Postorder: ");
    postorder(root);
    return 0;
}