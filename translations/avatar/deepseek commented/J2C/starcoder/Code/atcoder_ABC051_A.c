#include <stdio.h>
#include <stdlib.h>

int main()
{
    char a[10000];
    scanf("%[^\n]s", a);
    printf("%s", a);
    return 0;
}

