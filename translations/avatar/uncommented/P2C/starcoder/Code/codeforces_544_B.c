#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n, k, x = 0;
    scanf("%d %d", &n, &k);
    if (k <= max(n*n/2, n*n - (n*n/2)))
    {
        printf("YES\n");
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (i % 2 == j % 2 && x < k)
                {
                    printf("L");
                    x++;
                }
                else
                    printf("S");
            }
            printf("\n");
        }
    }
    else
        printf("NO");
    return 0;
}

