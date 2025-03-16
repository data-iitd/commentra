
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int in[3];
    int i;
    for (i = 0; i < 3; i++)
    {
        scanf("%d", &in[i]);
    }
    qsort(in, 3, sizeof(int), compare);
    printf("%d\n", in[2] * 10 + in[1] + in[0]);
    return 0;
}

int compare(const void *a, const void *b)
{
    return (*(int *)a - *(int *)b);
}

