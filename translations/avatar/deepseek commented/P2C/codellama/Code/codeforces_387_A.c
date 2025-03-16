
#include <stdio.h>

int main()
{
    int h1, m1, h2, m2;
    scanf("%d:%d", &h1, &m1);
    m1 += h1 * 60;
    scanf("%d:%d", &h2, &m2);
    m2 += h2 * 60;
    m2 = m1 - m2;
    m2 %= 1440;
    printf("%02d:%02d", m2 / 60, m2 % 60);
    return 0;
}

