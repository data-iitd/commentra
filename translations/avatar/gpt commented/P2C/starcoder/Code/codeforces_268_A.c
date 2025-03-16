#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n, i, j, k, count = 0;
    char **q;

    scanf("%d", &n);
    q = (char **)malloc(n * sizeof(char *));

    for (i = 0; i < n; i++)
    {
        q[i] = (char *)malloc(100 * sizeof(char));
        scanf("%s", q[i]);
    }

    for (j = 0; j < n; j++)
    {
        for (k = 0; k < n; k++)
        {
            if (j == k)
                continue;
            if (q[j][0] == q[k][strlen(q[k]) - 1])
                count++;
        }
    }

    printf("%d", count);

    return 0;
}

