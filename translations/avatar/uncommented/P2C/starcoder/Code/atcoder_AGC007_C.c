#include <stdio.h>
int main(void)
{
    int N, d, x, ret = 0;
    scanf("%d%d%d", &N, &d, &x);
    while (N)
    {
        ret += d + (N - 0.5) * x;
        d += d / N + (5 * x) / (2 * N);
        x += 2 * x / N;
        N--;
    }
    printf("%d", ret);
    return 0;
}
