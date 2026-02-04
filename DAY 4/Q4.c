/*
Problem: Given an array of n integers, reverse the array in-place using two-pointer approach.
Input:
- First line: integer n
- Second line: n space-separated integers
Output:
- Print the reversed array, space-separated
Example:
Input:
5
1 2 3 4 5
Output:
5 4 3 2 1
Explanation: Swap pairs from both ends: (1,5), (2,4), middle 3 stays
*/

#include<stdio.h>
int main()
{
    int n, i, j, temp;
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
    //Initialize start and end indexes
    i=0;
    j=n-1;
    //Reverse array using swapping
    while(i<j)
    {
        temp=arr[i];
        arr[i]=arr[j];
        arr[j]=temp;
        i++;
        j--;
    }
    //Display the updated array
    for(i=0; i<n; i++)
    {
        printf("%d ", arr[i]);
    }
    return 0;
}