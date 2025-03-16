
#include <stdio.h>
int main()
{
    int n, a, b;
    scanf("%d %d %d", &n, &a, &b);
    int lista[n], listb[n];
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &lista[i]);
    }
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &listb[i]);
    }
    for (int k = 0; k < n; k++)
    {
        if (lista[k] == k + 1)
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