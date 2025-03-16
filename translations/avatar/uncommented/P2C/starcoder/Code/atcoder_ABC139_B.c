#include <stdio.h>
int main(void)
{
    int a, b, hole, i;
    scanf("%d %d", &a, &b);
    hole = 1;
    i = 0;
    while (hole < b)
    {
        hole = a * (i + 1) - i;
        i++;
    }
    printf("%d", i);
    return 0;
}
