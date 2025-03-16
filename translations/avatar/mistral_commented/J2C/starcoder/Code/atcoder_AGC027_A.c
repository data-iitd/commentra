
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int N, i, num = 0;
    long x;
    scanf("%d", &N);
    scanf("%ld", &x);
    long *sweet = (long *)malloc(N * sizeof(long));
    for (i = 0; i < N; i++)
    {
        scanf("%ld", &sweet[i]);
    }
    qsort(sweet, N, sizeof(long), cmpfunc);
    for (i = 0; i < N; i++)
    {
        if (x - sweet[i] >= 0)
        {
            x -= sweet[i];
            num++;
        }
        else
        {
            break;
        }
    }
    if ((num == N) && (x > 0))
    {
        num--;
    }
    printf("%d\n", num);
    return 0;
}

int cmpfunc(const void *a, const void *b)
{
    return *(long *)a - *(long *)b;
}

