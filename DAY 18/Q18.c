/*
Problem: Given an array of integers, rotate the array to the right by k positions.
Input:
- First line: integer n
- Second line: n integers
- Third line: integer k
Output:
- Print the rotated array
Example:
Input:
5
1 2 3 4 5
2
Output:
4 5 1 2 3
*/

#include <stdio.h>

int main() 
{
    int n, k;
    //Read size of array
    printf("Enter number of elements: ");
    scanf("%d", &n);
    int arr[n];
    //Read array elements
    printf("Enter elements: ");
    for(int i = 0; i < n; i++) 
    {
        scanf("%d", &arr[i]);
    }
    //Read number of rotations
    printf("Enter number of rotations: ");
    scanf("%d", &k);
    //If k is greater than n, reduce it
    k = k % n;
    int temp[n];
    //Copy last k elements of arr into the beginning of temp
    for(int i = 0; i < k; i++) 
    {
        temp[i] = arr[n - k + i];
    }
    //Copy remaining elements of arr into temp after the last k elements
    for(int i = 0; i < n - k; i++) 
    {
        temp[k + i] = arr[i];
    }
    //Copy rotated elements back into original array
    for(int i = 0; i < n; i++) 
    {
        arr[i] = temp[i];
    }
    //Print rotated array
    for(int i = 0; i < n; i++) 
    {
        printf("%d ", arr[i]);
    }
    return 0;
}
