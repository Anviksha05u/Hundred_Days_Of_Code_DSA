/*
Problem: Write a program to check whether a given square matrix is an Identity Matrix. An identity matrix is a square matrix in which all diagonal elements are 1 and all non-diagonal elements are 0.
Input:
- First line: integer n representing number of rows and columns
- Next n lines: n integers each representing the matrix elements
Output:
- Print "Identity Matrix" if the matrix satisfies the condition
- Otherwise, print "Not an Identity Matrix"
Example:
Input:
3
1 0 0
0 1 0
0 0 1
Output:
Identity Matrix
*/

#include <stdio.h>
int main() 
{
    int n, i, j;
    int isIdentity = 1; //Assume it is identity first
    //Input size of matrix
    printf("Enter number of rows and columns: ");
    scanf("%d", &n);
    int matrix[n][n];
    //Input matrix elements
    printf("Enter elements: ");
    for(i = 0; i < n; i++) 
    {
        for(j = 0; j < n; j++) 
        {
            scanf("%d", &matrix[i][j]);
            //Check condition while reading
            if(i == j) 
            {
                //Diagonal element must be 1
                if(matrix[i][j] != 1) 
                {
                    isIdentity = 0;
                }
            }
            else 
            {
                //Non-diagonal element must be 0
                if(matrix[i][j] != 0) 
                {
                    isIdentity = 0;
                }
            }
        }
    }
    //Display result
    if(isIdentity)
    {
        printf("Identity Matrix\n");
    }
    else
    {
        printf("Not an Identity Matrix\n");
    }
    return 0;
}