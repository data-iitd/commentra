#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n, m;
    scanf("%d %d", &n, &m);
    char **ans = (char **)malloc(n * sizeof(char *));
    for (int i = 0; i < n; i++)
    {
        char *str = (char *)malloc(m * sizeof(char));
        scanf("%s", str);
        char *temp = (char *)malloc(m * sizeof(char));
        for (int j = 0; j < m; j++)
        {
            if (str[j] == '-')
            {
                temp[j] = '-';
            }
            else
            {
                if ((i + j) % 2 == 1)
                {
                    temp[j] = 'W';
                }
                else
                {
                    temp[j] = 'B';
                }
            }
        }
        ans[i] = temp;
    }
    for (int i = 0; i < n; i++)
    {
        printf("%s\n", ans[i]);
    }
    return 0;
}

