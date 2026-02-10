/*
Problem: Read a string and check if it is a palindrome using two-pointer comparison.
Input:
- Single line: string s
Output:
- Print YES if palindrome, otherwise NO
Example:
Input:
level
Output:
YES
Explanation: String reads same forwards and backwards
*/

#include<stdio.h>
#include<string.h>
int main()
{
    char str[100];
    //Input a string
    printf("Enter a string: ");
    scanf("%s", str);
    int i=0;
    int j=strlen(str)-1;
    int isPalindrome=1;
    //Compare characters from both ends 
    while(i<j)
    {
        
        if(str[i]!=str[j])
        {
            isPalindrome=0;
            break;
        }
        i++;
        j--;
    }
    //Display result
    if(isPalindrome)
    printf("YES\n");
    else
    printf("NO\n");
    return 0;
}