#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n;
    scanf("%d", &n);
    printf("%d\n", (n / 3) * 2 + (n % 3 == 0? 0 : 1));
    return 0;
}

