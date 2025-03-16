#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    int firstline, total, x, A, G;
    char *memory;
    firstline = atoi(argv[1]);
    total = 0;
    memory = (char *)malloc(firstline*sizeof(char));
    for(x=0;x<firstline;x++)
    {
        scanf("%d %d", &A, &G);
        if(total + A <= 500)
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
    printf("%s", memory);
    return 0;
}
