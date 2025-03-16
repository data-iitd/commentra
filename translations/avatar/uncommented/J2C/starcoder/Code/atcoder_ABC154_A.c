#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char str[1000];
    char u[1000];
    scanf("%s",str);
    scanf("%s",u);
    int a,b;
    scanf("%d %d",&a,&b);
    if(strcmp(str,u)==0)
    {
        printf("%d %d\n",a-1,b);
    }
    else
    {
        printf("%d %d\n",a,b-1);
    }
    return 0;
}
