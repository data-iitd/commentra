#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n, k, m, j, p, l;
    int *M;

    scanf("%d %d", &n, &k);
    M = (int *) malloc(n * sizeof(int));
    for (j = 0; j < n; j++)
    {
        scanf("%d", &M[j]);
    }

    for (j = 0; j < n; j++)
    {
        for (p = 0; p < n; p++)
        {
            if (0 == M[p])
            {
                printf("%d ", p + 1);
                break;
            }
        }

        for (l = 0; l < p + 1 - k; l++)
        {
            M[l] -= 1;
        }

        M[p] -= 1;
    }

    return 0;
}

