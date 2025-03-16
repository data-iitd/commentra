
#include <stdio.h>

int main()
{
    int firstline, total, A, G;
    char memory[1000];

    scanf("%d", &firstline);
    total = 0;
    for (int x = 0; x < firstline; x++)
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
    for (int x = 0; x < firstline; x++)
    {
        printf("%c", memory[x]);
    }
    printf("\n");
    return 0;
}

