/*
Problem: Given an array of integers, count the frequency of each distinct element and print the result.
Input:
- First line: integer n (size of array)
- Second line: n integers
Output:
- Print each element followed by its frequency in the format element:count
Example:
Input:
5
1 2 2 3 1
Output:
1:2 2:2 3:1
*/

#include <stdio.h>
int main() {
    int n;
    //Input size of the array
    printf("Enter size of array: ");
    scanf("%d", &n);
    int arr[n];
    //Input elements in the array
    printf("Enter elements: ");
    for(int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    //Array to mark if element is already counted
    int counted[n];
    for(int i = 0; i < n; i++)
    {
        counted[i] = 0;
    }
    //Count frequency
    for(int i = 0; i < n; i++) 
    {
        if(counted[i]) 
        continue; //Skip if already counted
        int freq = 1;
        for(int j = i + 1; j < n; j++) 
        {
            if(arr[i] == arr[j]) 
            {
                freq++;
                counted[j] = 1; //Mark as counted
            }
        }
        printf("%d:%d ", arr[i], freq);
    }
    return 0;
}