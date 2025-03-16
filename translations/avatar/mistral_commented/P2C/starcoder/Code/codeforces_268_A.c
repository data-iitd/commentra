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

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            if (q[i] == q[j])
            {
                continue;
            }
            if (q[j][0] == q[i][strlen(q[i]) - 1])
            {
                count++;
            }
        }
    }

    printf("%d", count);

    return 0;
}

