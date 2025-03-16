
#include <stdio.h>
#include <string.h>

int main()
{
    int n, count = 0;
    char *q[1000];

    scanf("%d", &n);

    for (int i = 0; i < n; i++)
    {
        q[i] = (char *)malloc(1000 * sizeof(char));
        scanf("%s", q[i]);
    }

    for (int j = 0; j < n; j++)
    {
        for (int k = 0; k < n; k++)
        {
            if (k == j)
                continue;
            else if (q[j][0] == q[k][strlen(q[k]) - 1])
                count++;
            else
                continue;
        }
    }

    printf("%d", count);

    return 0;
}

