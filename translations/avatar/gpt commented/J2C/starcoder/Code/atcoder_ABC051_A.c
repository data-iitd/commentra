#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char a[100000];
    scanf("%[^\n]s", a);
    char *b = strstr(a, ",");
    if (b!= NULL)
        *b ='';
    printf("%s", a);
    return 0;
}

