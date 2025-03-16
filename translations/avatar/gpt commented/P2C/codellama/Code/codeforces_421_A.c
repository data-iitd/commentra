#include <stdio.h>

int main()
{
    int n, a, b, k;
    scanf("%d %d %d", &n, &a, &b);

    int lista[n];
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &lista[i]);
    }

    int listb[n];
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &listb[i]);
    }

    for (k = 0; k < n; k++)
    {
        if (k + 1 == lista[k])
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

