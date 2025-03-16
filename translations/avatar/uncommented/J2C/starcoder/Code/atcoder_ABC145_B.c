#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int n;
    char str[100000];
    scanf("%d", &n);
    getchar();
    gets(str);
    int i;
    for(i=0;i<n/2;i++)
        printf("%c", str[i]);
    if(strcmp(str, str+n/2) == 0)
        printf("Yes");
    else
        printf("No");
    return 0;
}

