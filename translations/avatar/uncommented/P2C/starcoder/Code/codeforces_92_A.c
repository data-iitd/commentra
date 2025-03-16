#include <stdio.h>
#include <stdlib.h>
int main(int argc, char *argv[])
{
    int n, m, i;
    scanf("%d %d", &n, &m);
    i = 1;
    while (m >= i)
    {
        m -= i;
        i = (i % n) + 1;
    }
    printf("%d", m);
    return 0;
}
