
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

int main()
{
    double N, d, x, ans = 0.0;
    scanf("%lf %lf %lf", &N, &d, &x);

    while (N > 0.5)
    {
        ans += (d + x * (N - 0.5));
        d = (N + 1.0) * d / N + (5.0 * x) / (2.0 * N);
        x = (1.0 + (2.0 / N)) * x;
        N--;
    }

    printf("%.20lf", ans);
    return 0;
}

