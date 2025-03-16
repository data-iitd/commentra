#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char *inp[2];
    int n, m;
    char **ans;
    char *str;
    int i, j;

    scanf("%s", inp);
    n = atoi(inp[0]);
    m = atoi(inp[1]);
    ans = (char **)malloc(n * sizeof(char *));
    for (i = 0; i < n; i++)
    {
        ans[i] = (char *)malloc(m * sizeof(char));
        scanf("%s", str);
        for (j = 0; j < m; j++)
        {
            if (str[j] == '-')
                ans[i][j] = '-';
            else
            {
                if ((i + j) % 2 == 1)
                    ans[i][j] = 'W';
                else
                    ans[i][j] = 'B';
            }
        }
    }
    for (i = 0; i < n; i++)
    {
        printf("%s\n", ans[i]);
    }
    return 0;
}

