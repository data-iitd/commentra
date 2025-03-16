
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n, k, i, j, x;
    scanf("%d %d", &n, &k);
    x = 0;
    if (k <= (n * n) / 2 || k <= (n * n) - ((n * n) / 2))
    {
        printf("YES\n");
        for (i = 0; i < n; i++)
        {
            for (j = 0; j < n; j++)
            {
                if (i % 2 == j % 2 && x < k)
                {
                    printf("L");
                    x++;
                }
                else
                {
                    printf("S");
                }
            }
            printf("\n");
        }
    }
    else
    {
        printf("NO");
    }
    return 0;
}

