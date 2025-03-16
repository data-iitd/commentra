#include <stdio.h>
#include <stdlib.h>

int main()
{
    int result = 0;
    char str[100];
    scanf("%s", str);
    while(strcmp(str, "0")!= 0)
    {
        result++;
        scanf("%s", str);
    }
    printf("%d", result);
    return 0;
}
