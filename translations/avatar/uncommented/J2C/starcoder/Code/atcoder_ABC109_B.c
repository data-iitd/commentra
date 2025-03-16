#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int N;
    scanf("%d", &N);
    char **map = (char**)malloc(N*sizeof(char*));
    for(int i = 0; i < N; i++)
    {
        map[i] = (char*)malloc(100*sizeof(char));
        scanf("%s", map[i]);
    }
    int ans = 1;
    char **past = (char**)malloc(N*sizeof(char*));
    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < i; j++)
        {
            if(strcmp(map[i], past[j]) == 0)
            {
                ans = 0;
                break;
            }
        }
        past[i] = map[i];
        if(i!= 0)
        {
            if(map[i][0]!= map[i-1][strlen(map[i-1])-1])
            {
                ans = 0;
                break;
            }
        }
    }
    if(ans)
        printf("Yes\n");
    else
        printf("No\n");
    return 0;
}
