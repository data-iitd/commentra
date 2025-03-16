#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int N;
    scanf("%d", &N);
    char str[100000];
    char str2[100000];
    int i, j, k, l;
    int flag = 1;
    for(i = 0; i < N; i++)
    {
        scanf("%s", str);
        for(j = 0; j < i; j++)
        {
            if(strcmp(str, str2) == 0)
            {
                flag = 0;
                break;
            }
        }
        if(flag == 0)
            break;
        strcpy(str2, str);
    }
    if(flag == 0)
        printf("No\n");
    else
        printf("Yes\n");
    return 0;
}
