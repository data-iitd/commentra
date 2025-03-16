
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int N;
    scanf("%d", &N);
    char **map = (char **)malloc(N * sizeof(char *));
    for (int i = 0; i < N; i++)
    {
        map[i] = (char *)malloc(100 * sizeof(char));
        scanf("%s", map[i]);
    }
    int ans = 1;
    char **past = (char **)malloc(N * sizeof(char *));
    char *next = (char *)malloc(100 * sizeof(char));
    for (int i = 0; i < N; i++)
    {
        if (past[i] != NULL)
        {
            ans = 0;
            break;
        }
        past[i] = map[i];
        if (i != 0)
        {
            if (strcmp(next, map[i]) != 0)
            {
                ans = 0;
                break;
            }
        }
        next = map[i];
    }
    if (ans)
    {
        printf("Yes\n");
    }
    else
    {
        printf("No\n");
    }
    return 0;
}

