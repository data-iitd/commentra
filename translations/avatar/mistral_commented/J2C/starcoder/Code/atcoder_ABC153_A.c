#include <stdio.h>
#include <stdlib.h>

int main()
{
    int h, a, num;
    scanf("%d %d", &h, &a);
    num = 0;
    for (int i = 1; h > 0; i++)
    {
        h = h - a;
        num++;
    }
    printf("%d", num);
    return 0;
}
