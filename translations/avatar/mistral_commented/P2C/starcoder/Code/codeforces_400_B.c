#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n, m;
    scanf("%d %d", &n, &m);

    int *c = (int *)malloc(sizeof(int) * m);
    int i, j, k, l;

    for (i = 0; i < m; i++)
    {
        scanf("%d", &c[i]);
    }

    for (i = 0; i < m; i++)
    {
        for (j = 0; j < m; j++)
        {
            if (c[i] > c[j])
            {
                k = c[i] - c[j];
                for (l = 0; l < m; l++)
                {
                    if (c[l] == k)
                    {
                        printf("%d", k);
                        break;
                    }
                }
            }
        }
    }

    printf("\n