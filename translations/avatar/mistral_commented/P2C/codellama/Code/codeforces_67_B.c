#include <stdio.h>

int main()
{
    int n, k, i, j, p, l;
    int M[100];
    int m = 0;

    scanf("%d %d", &n, &k);

    for (i = 0; i < n; i++)
    {
        scanf("%d", &M[i]);
    }

    for (j = 0; j < n; j++)
    {
        for (p = 0; p < n; p++)
        {
            if (M[p] == 0)
            {
                printf("%d ", p + 1);
                break;
            }
        }

        for (l = p + 1 - k; l < p + 1; l++)
        {
            M[l]--;
        }

        M[p]--;
    }

    return 0;
}
