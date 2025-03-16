#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int x, t, a, b, da, db;
    char *xxs;
    xxs = (char *)malloc(100 * sizeof(char));
    scanf("%s", xxs);
    x = atoi(xxs);
    t = atoi(strtok(xxs, " "));
    a = atoi(strtok(NULL, " "));
    b = atoi(strtok(NULL, " "));
    da = atoi(strtok(NULL, " "));
    db = atoi(strtok(NULL, " "));
    free(xxs);
    if (x == 0)
    {
        printf("YES\n");
        return 0;
    }
    int a_time = min(a / da, t - 1);
    int b_time = min(b / db, t - 1);
    for (int i = 0; i <= a_time; i++)
    {
        for (int j = 0; j <= b_time; j++)
        {
            if (a - da * i == x || b - db * j == x)
            {
                printf("YES\n");
                return 0;
            }
            if (a - da * i + b - db * j == x)
            {
                printf("YES\n");
                return 0;
            }
        }
    }
    printf("NO\n");
    return 0;
}

