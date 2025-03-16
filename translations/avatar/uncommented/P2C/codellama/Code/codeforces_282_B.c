#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int firstline;
    int total = 0;
    char memory[1000];
    int x;
    int A, G;

    scanf("%d", &firstline);

    for (x = 0; x < firstline; x++)
    {
        scanf("%d %d", &A, &G);
        if (total + A <= 500)
        {
            total += A;
            memory[x] = 'A';
        }
        else
        {
            total -= G;
            memory[x] = 'G';
        }
    }

    for (x = 0; x < firstline; x++)
    {
        printf("%c", memory[x]);
    }

    return 0;
}

