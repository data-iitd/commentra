
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int h1, m1, h2, m2, m;

    scanf("%d:%d", &h1, &m1);
    m1 += h1 * 60;
    scanf("%d:%d", &h2, &m2);
    m2 += h2 * 60;
    m = m1 - m2;
    m %= 1440;
    printf("%02d:%02d", m / 60, m % 60);

    return 0;
}

