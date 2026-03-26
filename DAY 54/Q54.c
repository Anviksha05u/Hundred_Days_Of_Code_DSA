/*
Problem Statement:
Perform zigzag (spiral) level order traversal of a binary tree. Alternate levels should be traversed left-to-right and right-to-left.
Input Format:
- First line contains integer N
- Second line contains level-order traversal (-1 indicates NULL)
Output Format:
- Print traversal in zigzag order
Example:
Input:
7
1 2 3 4 5 6 7
Output:
1 3 2 4 5 6 7
Explanation:
Level 1 is printed left-to-right, level 2 right-to-left, and so on.
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
//Zigzag traversal
void zigzagTraversal(struct Node* root)
{
    if(root == NULL) return;
    struct Node* queue[1000];
    int front = 0, rear = 0;
    queue[rear++] = root;
    int leftToRight = 1;
    while(front < rear)
    {
        int size = rear - front;
        int temp[size]; //Store current level
        for(int i = 0; i < size; i++)
        {
            struct Node* curr = queue[front++];
            //Normal or reverse index
            int index = leftToRight ? i : (size - 1 - i);
            temp[index] = curr->data;
            if(curr->left)
                queue[rear++] = curr->left;
            if(curr->right)
                queue[rear++] = curr->right;
        }
        //Print level
        for(int i = 0; i < size; i++)
            printf("%d ", temp[i]);
        //Change direction
        leftToRight = !leftToRight;
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
    printf("Zigzag Traversal: ");
    zigzagTraversal(root);
    return 0;
}