/*
Problem Statement
Given an array of integers containing both positive and negative values, find the length of the longest contiguous subarray whose sum is equal to zero.
Input Format
An integer array arr[].
Output Format
Print the length of the longest subarray with sum equal to zero.
Sample Input
15 -2 2 -8 1 7 10 23
Sample Output
5
Explanation
The subarray [-2, 2, -8, 1, 7] has a sum of 0 and is the longest such subarray.
*/

#include <stdio.h>
#define MAX 1000
int main()
{
    int n;
    printf("Enter number of elements: ");
    scanf("%d", &n);
    int arr[MAX];
    printf("Enter elements:\n");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    int sum = 0;
    int maxLen = 0;
    //Hash map simulation (store first occurrence of sum)
    int map[2001]; //Supports sums from -1000 to +1000 (adjust if needed)
    for (int i = 0; i < 2001; i++)
    {
        map[i] = -2; //-2 means not visited
    }
    //Sum = 0 at index -1
    map[1000] = -1;
    for (int i = 0; i < n; i++)
    {
        sum += arr[i];
        int index = sum + 1000; //Shift for negative values
        if (map[index] != -2)
        {
            int len = i - map[index];
            if (len > maxLen)
            {
                maxLen = len;
            }
        }
        else
        {
            map[index] = i;
        }
    }
    printf("Length of longest subarray with sum 0: %d\n", maxLen);
    return 0;
}