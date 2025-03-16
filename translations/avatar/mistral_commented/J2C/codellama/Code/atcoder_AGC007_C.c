
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    double N, d, x;
    double ans = 0.0;

    // Reading input values from the user
    scanf("%lf %lf %lf", &N, &d, &x);

    // Calculating the answer using the given formula
    while (N > 0.5)
    {
        double adnum = d + x * (N - 0.5);
        ans += adnum;

        // Updating the values of d and x for the next iteration
        d = (N + 1.0) * d / N + (5.0 * x) / (2.0 * N);
        x = (1.0 + (2.0 / N)) * x;

        --N;
    }

    // Formatting the output with 20 decimal places
    printf("%.20lf\n", ans);

    return 0;
}

