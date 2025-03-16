#include <stdio.h>
#include <stdlib.h>

int main()
{
    char *str = malloc(100);
    scanf("%s", str);
    printf("%s", str);
    return 0;
}
