#include <stdio.h>
#include <stdlib.h>

int main()
{
    int firstline, A, G, total, i;
    char *memory;

    scanf("%d", &firstline);
    total = 0;
    memory = (char *)malloc(firstline * sizeof(char));

    for (i = 0; i < firstline; i++)
    {
        scanf("%d %d", &A, &G);
        if (total + A <= 500)
        {
            total += A;
            memory[i] = 'A';
        }
        else
        {
            total -= G;
            memory[i] = 'G';
        }
    }

    printf("%s", memory);

    return 0;
}

