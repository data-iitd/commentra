#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int n, i, j, k, l, m, f, c;
    char s[100000][100000], t[100000];
    scanf("%d", &n);
    for (i = 0; i < n; i++)
        scanf("%s", s[i]);
    f = 1;
    for (i = 0; i < n; i++)
    {
        c = 0;
        for (j = 0; j < n; j++)
        {
            if (i == j)
                continue;
            for (k = 0; k < strlen(s[i]); k++)
            {
                for (l = 0; l < strlen(s[j]); l++)
                {
                    if (s[i][k] == s[j][l])
                    {
                        c = 1;
                        break;
                    }
                }
                if (c == 1)
                    break;
            }
            if (c == 0)
            {
                f = 0;
                break;
            }
        }
        if (f == 0)
            break;
    }
    if (f == 1)
        printf("Yes\n");
    else
        printf("No\n");
    return 0;
}

