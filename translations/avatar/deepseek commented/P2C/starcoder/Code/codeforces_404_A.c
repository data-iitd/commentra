
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int n;
    scanf("%d", &n);
    char s[n][n];
    for (int i = 0; i < n; i++)
    {
        scanf("%s", s[i]);
    }
    int flag = 0;
    char d1[n];
    char d2[n];
    char rem[n];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i == j)
            {
                d1[i] = s[i][j];
            }
            if (i == n - j - 1)
            {
                d2[i] = s[i][j];
            }
            if (i!= j && i!= n - j - 1)
            {
                rem[i] = s[i][j];
            }
        }
    }
    if (strlen(rem)!= 1)
    {
        printf("NO");
    }
    else if (strcmp(d1, d2)!= 0)
    {
        printf("NO");
    }
    else if (strlen(rem)!= 1)
    {
        printf("NO");
    }
    else if (strcmp(d1, rem) == 0)
    {
        printf("NO");
    }
    else
    {
        printf("YES");
    }
    return 0;
}

