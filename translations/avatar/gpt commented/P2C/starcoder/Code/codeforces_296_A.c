#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int n;
    scanf("%d", &n);
    char *m[100000];
    int i, j, count;
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
            printf("NO\n");
            return 0;
        }
    }
    printf("YES\n");
    return 0;
}

