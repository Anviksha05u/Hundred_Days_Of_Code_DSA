/*
Problem: Write a recursive function fib(n) to compute the n-th Fibonacci number where fib(0)=0 and fib(1)=1.
Input:
- Single integer n
Output:
- Print the n-th Fibonacci number
Example:
Input:
6
Output:
8
Explanation: Sequence: 0,1,1,2,3,5,8 at positions 0,1,2,3,4,5,6
*/

#include <stdio.h>
//Recursive function to find fibonacci number
int fib(int n)
{
    //Base case
    if(n==0)
    return 0;
    if(n==1)
    return 1;
    //Recursive case
    return fib(n-1)+fib(n-2);
}
int main()
{
    int n;
    //Input a number
    printf("Enter a number: ");
    scanf("%d", &n);
    //Display result
    printf("%d", fib(n));
    return 0;
}