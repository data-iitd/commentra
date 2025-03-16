
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char str[1000000];
    scanf("%s",str);
    int n=strlen(str);
    char a[n/2];
    for(int i=0;i<n/2;i++)
        a[i]=str[i];
    if(strcmp(str,a+a)==0)
        printf("Yes\n");
    else
        printf("No\n");
    return 0;
}

