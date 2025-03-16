
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int n;
    scanf("%d", &n);
    if(n == 1)
    {
        printf("Hello World\n");
    }
    else
    {
        int num1, num2;
        scanf("%d %d", &num1, &num2);
        printf("%d\n", num1 + num2);
    }
    return 0;
}

