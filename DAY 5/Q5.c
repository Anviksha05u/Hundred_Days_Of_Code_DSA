/*
Problem: A system receives two separate logs of user arrival times from two different servers. Each log is already sorted in ascending order. Your task is to create a single chronological log that preserves the correct order of arrivals.
Input:
- First line: integer p (number of entries in server log 1)
- Second line: p sorted integers representing arrival times from server 1
- Third line: integer q (number of entries in server log 2)
- Fourth line: q sorted integers representing arrival times from server 2)
Output:
- Print a single line containing all arrival times in chronological order, separated by spaces
Example:
Input:
5
10 20 30 50 70
4
15 25 40 60
Output:
10 15 20 25 30 40 50 60 70
Explanation: Compare the next unprocessed arrival time from both logs and append the earlier one to the final log until all entries are processed
*/


#include<stdio.h>
int main()
{
    int p, q, i, j, k;
    //Input number of entries in server log 1
    printf("Enter number of entries in server log 1: ");
    scanf("%d", &p);
    int a[p];
    //Input sorted integers
    printf("Enter sorted integers for server log 1: ");
    for(i=0; i<p; i++)
    {
        scanf("%d", &a[i]);
    }
    //Input number of entries in server log 2
    printf("Enter number of entries in server log 2: ");
    scanf("%d", &q);
    int b[q];
    //Input sorted integers
    printf("Enter sorted integers for server log 2: ");
    for(j=0; j<q; j++)
    {
        scanf("%d", &b[j]);
    }
    int c[p+q];
    i = 0;
    j = 0;
    k = 0;
    //Merge
    while(i<p && j<q)
    {
        if(a[i]<b[j])
        {
            c[k++]=a[i++];
        }
        else
        {
            c[k++]=b[j++];
        }
    }
    //Copying remaining elements of a[i] and b[j]
    while(i<p)
    {
        c[k++]=a[i++];
    }
    while(j<q)
    {
        c[k++]=b[j++];
    }
    //Display the updated array
    for(i=0; i<k; i++)
    {
        printf("%d ", c[i]);
    }
    printf("\n");
    return 0;
}
