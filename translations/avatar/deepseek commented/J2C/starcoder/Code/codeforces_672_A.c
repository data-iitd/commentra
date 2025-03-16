
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int n;
    char str[1000];
    int i;
    for(i=1;i<=1000;i++)
    {
        str[i-1] = i;
    }
    scanf("%d",&n);
    printf("%c",str[n-1]);
    return 0;
}

