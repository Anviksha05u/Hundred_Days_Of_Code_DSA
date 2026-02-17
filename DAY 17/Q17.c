/*
Problem: Write a program to find the maximum and minimum values present in a given array of integers.
Input:
- First line: integer n
- Second line: n integers
Output:
- Print the maximum and minimum elements
Example:
Input:
6
3 5 1 9 2 8
Output:
Max: 9
Min: 1
*/

#include <stdio.h>
int main() 
{
    int n;
    //Input size of the array
    printf("Enter number of elements: ");
    scanf("%d", &n);
    int arr[n];
    //Input array elements
    printf("Enter integers: ");
    for(int i = 0; i < n; i++) 
    {
        scanf("%d", &arr[i]);
    }
    //Initialize max and min to the first element
    int max = arr[0];
    int min = arr[0];
    //Traverse the array to find max and min
    for(int i = 1; i < n; i++) 
    {
        if(arr[i] > max) 
        {
            max = arr[i]; //Update max if current element is greater
        }
        if(arr[i] < min) 
        {
            min = arr[i]; //Update min if current element is smaller
        }
    }
    //Display the results
    printf("Max: %d\n", max);
    printf("Min: %d\n", min);
    return 0;
}