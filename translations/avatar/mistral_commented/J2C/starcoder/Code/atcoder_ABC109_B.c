
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int N;
    scanf("%d", &N);
    char str[1000000];
    int i, j, k, l;
    int flag = 1;
    char prev[1000000];
    char next[1000000];
    for(i = 0; i < N; i++)
    {
        scanf("%s", str);
        for(j = 0; j < i; j++)
        {
            if(strcmp(str, prev) == 0)
            {
                flag = 0;
                break;
            }
        }
        if(flag == 0)
            break;
        strcpy(prev, str);
        strcpy(next, str);
        for(k = 0; k < strlen(str); k++)
        {
            next[k] = str[strlen(str) - 1 - k];
        }
        if(strcmp(next, prev)!= 0)
        {
            flag = 0;
            break;
        }
    }
    if(flag == 1)
        printf("Yes\n");
    else
        printf("No\n");
    return 0;
}

