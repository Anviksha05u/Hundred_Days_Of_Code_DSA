/*
Problem Statement
Implement a hash table using quadratic probing with formula:
h(k, i) = (h(k) + i*i) % m
Input Format
Same as previous.
Output Format
Result of SEARCH operations.
Sample Input
7
4
INSERT 49
INSERT 56
SEARCH 49
SEARCH 15
Sample Output
FOUND
NOT FOUND
Explanation
Collisions resolved using i² jumps.
*/

#include <stdio.h>
#define EMPTY -1
int main()
{
    int m, q;
    printf("Enter size of hash table: ");
    scanf("%d", &m);
    int table[m];
    //Initialize table
    for (int i = 0; i < m; i++)
    {
        table[i] = EMPTY;
    }
    printf("Enter number of operations: ");
    scanf("%d", &q);
    for (int i = 0; i < q; i++)
    {
        char op[10];
        int key;
        scanf("%s %d", op, &key);
        //INSERT operation
        if (op[0] == 'I')
        {
            int h = key % m;
            int j = 0;
            while (j < m)
            {
                int index = (h + j * j) % m;
                if (table[index] == EMPTY)
                {
                    table[index] = key;
                    break;
                }
                j++;
            }
        }
        //SEARCH operation
        else if (op[0] == 'S')
        {
            int h = key % m;
            int j = 0;
            int found = 0;
            while (j < m)
            {
                int index = (h + j * j) % m;
                if (table[index] == key)
                {
                    found = 1;
                    break;
                }
                if (table[index] == EMPTY)
                {
                    break;
                }
                j++;
            }
            if (found)
                printf("FOUND\n");
            else
                printf("NOT FOUND\n");
        }
    }
    return 0;
}