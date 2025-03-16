#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n, k, m, j, p, l;
    int *M;

    scanf("%d %d", &n, &k);
    M = (int *)malloc(n * sizeof(int));
    m = 0;

    for (j = 0; j < n; j++)
    {
        for (p = 0; p < n; p++)
        {
            if (M[p] == 0)
            {
                printf("%d ", p + 1);
                m++;
                break;
            }
        }

        for (l = p + 1 - k; l < p; l++)
        {
            M[l]--;
        }

        M[p]--;
    }

    printf("\n");
    return 0;
}

