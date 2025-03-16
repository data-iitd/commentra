#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n, i, j, flag = 0;
    char **s, *rem[1000];
    scanf("%d", &n);
    s = (char**)malloc(n * sizeof(char*));
    for (i = 0; i < n; i++)
    {
        s[i] = (char*)malloc(n * sizeof(char));
        scanf("%s", s[i]);
    }
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            if (i == j)
            {
                printf("%c", s[i][j]);
            }
            if (i == n - j - 1)
            {
                printf("%c", s[i][j]);
            }
            if (i!= j && i!= n - j - 1)
            {
                rem[i] = s[i][j];
            }
        }
    }
    if (rem[0] == rem[1] && rem[0] == rem[2] && rem[0] == rem[3] && rem[0] == rem[4] && rem[0] == rem[5] && rem[0] == rem[6] && rem[0] == rem[7] && rem[0] == rem[8] && rem[0] == rem[9])
    {
        printf("YES");
    }
    else
    {
        printf("NO");
    }
    return 0;
}
