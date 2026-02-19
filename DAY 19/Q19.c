/*
Problem: Given an array of integers, find two elements whose sum is closest to zero.
Input:
- First line: integer n
- Second line: n space-separated integers
Output:
- Print the pair of elements whose sum is closest to zero
Example:
Input:
5
1 60 -10 70 -80
Output:
-10 1
Explanation: Among all possible pairs, the sum of -10 and 1 is -9, which is the closest to zero compared to other pairs.
*/

#include <stdio.h>
#include <stdlib.h>
int main() 
{
    int n;
    //Read size of array
    printf("Enter number of elements: ");
    scanf("%d", &n);
    int arr[n];
    printf("Enter elements: ");
    //Read array elements
    for(int i = 0; i < n; i++) 
    {
        scanf("%d", &arr[i]);
    }
    int minSum = abs(arr[0] + arr[1]);
    int x = arr[0], y = arr[1];
    //Check all pairs
    for(int i = 0; i < n; i++) 
    {
        for(int j = i + 1; j < n; j++) 
        {
            int sum = abs(arr[i] + arr[j]);
            //Update minimum sum if current pair is closer to zero
            if(sum < minSum) 
            {
                minSum = sum;
                x = arr[i];
                y = arr[j];
            }
        }
    }
    //Print the result
    printf("%d %d", y, x);
    return 0;
}