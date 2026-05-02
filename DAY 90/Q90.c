/*
Problem Statement
Given n boards of different lengths and k painters, each painter paints contiguous boards. Painting a unit length of board takes one unit of time.
Determine the minimum time required to paint all boards.
Input Format
n k
n space-separated integers representing board lengths
Output Format
Print the minimum time required to paint all boards.
Sample Input
4 2
10 20 30 40
Sample Output
60
Explanation
One painter paints boards of length 10, 20, and 30 (total 60), while the other paints board of length 40.
*/

#include <stdio.h>
//Check if allocation is possible within maxTime
int canPaint(int boards[], int n, int k, int maxTime)
{
    int painters = 1;
    int time = 0;
    for (int i = 0; i < n; i++)
    {
        if (time + boards[i] <= maxTime)
        {
            time += boards[i];
        }
        else
        {
            painters++;
            time = boards[i];
            if (painters > k)
                return 0;
        }
    }
    return 1;
}
int main()
{
    int n, k;
    scanf("%d %d", &n, &k);
    int boards[n];
    int sum = 0, maxVal = 0;
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &boards[i]);
        sum += boards[i];
        if (boards[i] > maxVal)
            maxVal = boards[i];
    }
    int low = maxVal;
    int high = sum;
    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (canPaint(boards, n, k, mid))
        {
            high = mid - 1; //Try better (less time)
        }
        else
        {
            low = mid + 1;
        }
    }
    printf("%d", low);
    return 0;
}