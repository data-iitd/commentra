
#include <stdio.h>
#include <math.h>
int main()
{
    int n, x;
    scanf("%d", &n);
    x = 1;
    while (log2(n) % 1)
    {
        x++;
        n -= pow(2, (int)log2(n));
    }
    printf("%d", x);
    return 0;
}
