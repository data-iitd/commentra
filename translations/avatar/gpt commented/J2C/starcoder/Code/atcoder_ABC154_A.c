#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char str[1000];
    char u[1000];
    int a,b;
    scanf("%s",str);
    scanf("%d %d", &a, &b);
    scanf("%s",u);
    if(strcmp(u,str)==0)
    {
        printf("%d %d\n",a-1,b);
    }
    else
    {
        printf("%d %d\n",a,b-1);
    }
    return 0;
}

