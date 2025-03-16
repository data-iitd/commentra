#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main()
{
    int n, i, j, count;
    char *m[1000];
    char *temp;
    int flag = 0;

    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        scanf("%s", m[i]);
    }

    for (i = 0; i < n; i++)
    {
        count = 0;
        for (j = 0; j < n; j++)
        {
            if (strcmp(m[i], m[j]) == 0)
            {
                count++;
            }
        }
        if (count >= n / 2 + 1)
        {
            flag = 1;
            break;
        }
    }

    if (flag == 1)
    {
        printf("NO");
    }
    else
    {
        printf("YES");
    }

    return 0;
}

