/*
Problem Statement:
Given a binary tree, print its vertical order traversal. Nodes that lie on the same vertical line should be printed together from top to bottom and from left to right.
Input Format:
- First line contains integer N (number of nodes)
- Second line contains N space-separated integers representing level-order traversal (-1 indicates NULL)
Output Format:
- Print nodes column by column from leftmost to rightmost vertical line
Example:
Input:
7
1 2 3 4 5 6 7
Output:
4
2
1 5 6
3
7
Explanation:
Vertical lines are formed based on horizontal distance from root. Nodes sharing the same distance are printed together.
*/

#include <stdio.h>
#include <stdlib.h>
//Tree node
struct Node
{
    int data;
    struct Node *left, *right;
};
//Queue node (to store node + HD)
struct QNode
{
    struct Node* node;
    int hd;
};
//Create new tree node
struct Node* createNode(int val)
{
    struct Node* node=(struct Node*)malloc(sizeof(struct Node));
    node->data=val;
    node->left=node->right=NULL;
    return node;
}
//Build tree from level order
struct Node* buildTree(int arr[], int n)
{
    if(n==0 || arr[0]==-1)
        return NULL;
    struct Node* root=createNode(arr[0]);
    struct Node* queue[n];
    int front=0, rear=0;
    queue[rear++]=root;
    int i=1;
    while(i<n)
    {
        struct Node* curr=queue[front++];
        if(arr[i]!=-1)
        {
            curr->left=createNode(arr[i]);
            queue[rear++]=curr->left;
        }
        i++;
        if(i<n && arr[i]!=-1) 
        {
            curr->right=createNode(arr[i]);
            queue[rear++]=curr->right;
        }
        i++;
    }
    return root;
}
//Vertical Order Traversal
void verticalOrder(struct Node* root)
{
    if(root==NULL)
    return;
    //Queue for BFS
    struct QNode queue[1000];
    int front=0, rear=0;
    //Store results
    int hd[1000], val[1000];
    int count = 0;
    int minHD=0, maxHD=0;
    //Push root
    queue[rear++]=(struct QNode){root, 0};
    while(front<rear)
    {
        struct QNode temp=queue[front++];
        struct Node* curr=temp.node;
        int h=temp.hd;
        hd[count]=h;
        val[count]=curr->data;
        count++;
        if(h<minHD) minHD=h;
        if(h>maxHD) maxHD=h;
        if(curr->left)
            queue[rear++]=(struct QNode){curr->left, h - 1};
        if(curr->right)
            queue[rear++]=(struct QNode){curr->right, h + 1};
    }
    //Print column-wise
    for(int i=minHD; i<=maxHD; i++)
    {
        for(int j=0; j<count; j++)
        {
            if(hd[j]==i)
                printf("%d ", val[j]);
        }
        printf("\n");
    }
}
int main()
{
    int n;
    printf("Enter number of nodes: ");
    scanf("%d", &n);
    int arr[n];
    printf("Enter level order (-1 for NULL): ");
    for(int i=0; i<n; i++)
        scanf("%d", &arr[i]);
    struct Node* root=buildTree(arr, n);
    printf("Vertical Order Traversal: \n");
    verticalOrder(root);
    return 0;
}