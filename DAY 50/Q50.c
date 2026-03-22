/*
Problem: BST Search
Implement the solution for this problem.
Input:
- Input specifications
Output:
- Output specifications
*/

#include <stdio.h>
#include <stdlib.h>
//Tree Node
struct TreeNode 
{
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};
//Create new node
struct TreeNode* createNode(int val) 
{
    struct TreeNode* node = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    node->val = val;
    node->left = node->right = NULL;
    return node;
}
//Insert into BST
struct TreeNode* insert(struct TreeNode* root, int val) 
{
    if(root == NULL)
        return createNode(val);
    if(val < root->val)
        root->left = insert(root->left, val);
    else
        root->right = insert(root->right, val);
    return root;
}
//Search BST
int searchBST(struct TreeNode* root, int val) 
{
    while(root != NULL) {
        if(root->val == val)
            return 1;
        else if(val < root->val)
            root = root->left;
        else
            root = root->right;
    }
    return 0;
}
int main() 
{
    int n, val, searchVal;
    struct TreeNode* root = NULL;
    printf("Enter number of nodes: ");
    scanf("%d", &n);
    printf("Enter elements:\n");
    for(int i = 0; i < n; i++) {
        scanf("%d", &val);
        root = insert(root, val);
    }
    printf("Enter value to search: ");
    scanf("%d", &searchVal);
    if(searchBST(root, searchVal))
        printf("Found\n");
    else
        printf("Not Found\n");
    return 0;
}