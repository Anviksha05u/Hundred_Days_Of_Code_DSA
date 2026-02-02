/*
Problem: Write a C program to delete the element at a given 1-based position pos from an array of n integers. Shift remaining elements to the left.
Input:
- First line: integer n
- Second line: n space-separated integers
- Third line: integer pos (1-based position to delete)
Output:
- Print the updated array with (n-1) elements, space-separated
Example:
Input:
5
10 20 30 40 50
2
Output:
10 30 40 50
Explanation: Delete position 2 (element 20), remaining elements shift left
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
    int pos;
    //Input position of the element to be deleted
    printf("Enter position of the element to be deleted: ");
    scanf("%d", &pos);
    //Shift elements to the left
    for(i=pos-1; i<n-1; i++)
    {
        arr[i]=arr[i+1];
    }
    n--;
    //Display the updated array
    for(i=0; i<n; i++)
    {
        printf("%d ", arr[i]);
    }
    return 0;
}