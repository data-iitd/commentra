
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    double N, d, x;
    double adnum, ans;
    int i;

    scanf("%lf", &N);
    scanf("%lf", &d);
    scanf("%lf", &x);

    ans = 0.0;
    for (i = 0; i < N; i++)
    {
        adnum = d + x * (N - 0.5);
        ans += adnum;
        d = (N + 1.0) * d / N + (5.0 * x) / (2.0 * N);
        x = (1.0 + (2.0 / N)) * x;
    }

    printf("%.20lf", ans);

    return 0;
}

