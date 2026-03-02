/*
Problem: Polynomial Using Linked List - Implement using linked list with dynamic memory allocation.
Input:
- First line: integer n (number of terms)
- Next n lines: two integers (coefficient and exponent)
Output:
- Print polynomial in standard form, e.g., 10x^4 + 20x^3 + 30x^2 + 40x + 50
Example:
Input:
5
10 4
20 3
30 2
40 1
50 0
Output:
10x^4 + 20x^3 + 30x^2 + 40x + 50
Explanation:
Each node stores coefficient and exponent. Traverse nodes to print polynomial in decreasing exponent order.
*/

#include <stdio.h>
#include <stdlib.h>
//Structure to store a polynomial term
typedef struct Term 
{
    int coeff; //Coefficient
    int exp; //Exponent
    struct Term* next; //Pointer to next term
} Term;
//Function to create a new term node
Term* createTerm(int coeff, int exp) 
{
    Term* newTerm=(Term*)malloc(sizeof(Term));
    newTerm->coeff=coeff;
    newTerm->exp=exp;
    newTerm->next=NULL;
    return newTerm;
}
//Function to print the polynomial
void printPolynomial(Term* head) 
{
    Term* curr=head;
    while (curr!=NULL) 
    {
        //Print coefficient and exponent
        if (curr->exp==0)
            printf("%d", curr->coeff);
        else if (curr->exp==1)
            printf("%dx", curr->coeff);
        else
            printf("%dx^%d", curr->coeff, curr->exp);
        //Print + if not last term
        if (curr->next!=NULL)
            printf(" + ");
        curr=curr->next;
    }
    printf("\n");
}
int main() 
{
    int n, coeff, exp;
    Term *head=NULL, *tail=NULL;
    //Input number of terms
    printf("Enter number of terms: ");
    scanf("%d", &n);
    //Input each term
    for (int i=0; i<n; i++) 
    {
        printf("Enter coefficient and exponent: ");
        scanf("%d %d", &coeff, &exp);
        Term* newTerm=createTerm(coeff, exp);
        //Insert at end of list
        if (head==NULL)
            head=tail=newTerm;
        else 
        {
            tail->next=newTerm;
            tail=newTerm;
        }
    }
    //Print polynomial
    printPolynomial(head);
    return 0;
}