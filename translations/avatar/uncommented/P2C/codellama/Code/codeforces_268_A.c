
#include <stdio.h>
#include <string.h>

int main()
{
    int n, i, j, k, count = 0;
    char a[100][100];

    scanf("%d", &n);

    for (i = 0; i < n; i++)
    {
        scanf("%s", a[i]);
    }

    for (j = 0; j < n; j++)
    {
        for (k = 0; k < n; k++)
        {
            if (k == j)
            {
                continue;
            }
            else if (a[j][0] == a[k][strlen(a[k]) - 1])
            {
                count++;
            }
            else
            {
                continue;
            }
        }
    }

    printf("%d", count);

    return 0;
}

