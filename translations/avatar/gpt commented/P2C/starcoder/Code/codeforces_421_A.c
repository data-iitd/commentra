#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n, a, b, i;
    scanf("%d %d %d", &n, &a, &b);
    int lista[n], listb[n];
    for (i = 0; i < n; i++)
    {
        scanf("%d", &lista[i]);
    }
    for (i = 0; i < n; i++)
    {
        scanf("%d", &listb[i]);
    }
    for (i = 0; i < n; i++)
    {
        if (i + 1 == lista[i])
        {
            printf("1 ");
        }
        else
        {
            printf("2 ");
        }
    }
    return 0;
}
