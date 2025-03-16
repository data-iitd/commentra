#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n, i;
    int *d;
    scanf("%d", &n);
    d = (int *)malloc(n * sizeof(int));
    for (i = 0; i < n; i++)
    {
        scanf("%d", &d[i]);
    }
    printf("%d\n", n);
    for (i = 0; i < n; i++)
    {
        printf("%d ", d[i]);
    }
    printf("\n