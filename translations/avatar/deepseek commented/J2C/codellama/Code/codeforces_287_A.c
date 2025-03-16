
#include <stdio.h>
#include <string.h>

int main()
{
    char str[4][100];
    int i, j, k, u, yes;
    for (i = 0; i < 4; i++)
    {
        scanf("%s", str[i]);
    }
    for (u = 0; u < 2; u++)
    {
        for (i = 0; i < 2; i++)
        {
            for (j = 0; j < 2; j++)
            {
                if (str[u][i] == str[u][i + 1] && (str[u + 1][i] == str[u][i] || str[u + 1][i + 1] == str[u][i]))
                {
                    yes = 1;
                    printf("YES\n");
                    break;
                }
                else if (str[u + 1][i] == str[u + 1][i + 1] && (str[u][i] == str[u + 1][i] || str[u][i + 1] == str[u + 1][i]))
                {
                    yes = 1;
                    printf("YES\n");
                    break;
                }
            }
            if (yes == 1)
            {
                break;
            }
        }
        if (yes == 1)
        {
            break;
        }
    }
    if (yes == 0)
    {
        printf("NO\n");
    }
    return 0;
}

