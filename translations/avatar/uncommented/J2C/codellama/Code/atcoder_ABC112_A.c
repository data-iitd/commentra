
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int n;
    scanf("%d", &n);
    if (n == 1)
    {
        printf("Hello World\n");
    }
    else
    {
        char str1[100], str2[100];
        scanf("%s %s", str1, str2);
        printf("%d\n", atoi(str1) + atoi(str2));
    }
    return 0;
}

