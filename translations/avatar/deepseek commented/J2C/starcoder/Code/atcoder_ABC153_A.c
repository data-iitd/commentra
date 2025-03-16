
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int h, a, num;
    scanf("%d %d", &h, &a);
    num = 0;
    while(h > 0)
    {
        h = h - a;
        num++;
    }
    printf("%d", num);
    return 0;
}

