/*
Problem: Given a sorted array of n integers, remove duplicates in-place. Print only unique elements in order.
Input:
- First line: integer n
- Second line: n space-separated integers (sorted array)
Output:
- Print unique elements only, space-separated
Example:
Input:
6
1 1 2 2 3 3
Output:
1 2 3
Explanation: Keep first occurrence of each element: 1, 2, 3
*/

#include<stdio.h>
int main()
{
    int n, i;
    //Input number of elements
    printf("Enter number of elements in an array: ");
    scanf("%d", &n);
    int arr[n];
    //Input array elements
    printf("Enter elements in the array: ");
    for(i=0; i<n; i++)
    {
        scanf("%d", &arr[i]);
    }
    //To store the index of last unique element
    int j=0;
    //Traverse array from second element
    for(i=1; i<n; i++)
    {
        if(arr[i]!=arr[j])
        {
            j++;
            arr[j]=arr[i];
        }
    }
    //Display the updated array
    for(i=0; i<=j; i++)
    {
        printf("%d ", arr[i]);
    }
    return 0;
}