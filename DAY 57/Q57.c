/*
Problem Statement:
Convert a binary tree into its mirror image by swapping left and right children at every node.
Input Format:
- First line contains integer N
- Second line contains level-order traversal (-1 indicates NULL)
Output Format:
- Print inorder traversal of mirrored tree
Example:
Input:
7
1 2 3 4 5 6 7
Output:
7 3 6 1 5 2 4
Explanation:
Each node’s left and right children are swapped recursively.
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
    return root;
}
//Convert to mirror
void mirrorTree(struct Node* root)
{
    if(root == NULL)
        return;
    //Swap left and right
    struct Node* temp = root->left;
    root->left = root->right;
    root->right = temp;
    //Recurse
    mirrorTree(root->left);
    mirrorTree(root->right);
}
//Inorder traversal
void inorder(struct Node* root)
{
    if(root == NULL)
        return;
    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
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
    //Convert to mirror
    mirrorTree(root);
    printf("Inorder of Mirror Tree: ");
    inorder(root);
    return 0;
}