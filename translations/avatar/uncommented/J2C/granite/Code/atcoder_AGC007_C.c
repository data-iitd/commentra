
#include <stdio.h>
#include <math.h>
#include <string.h>

int main() {
    double N, d, x;
    scanf("%lf %lf %lf", &N, &d, &x);
    double ans = 0.0;
    while (N > 0.5) {
        double adnum = d + x * (N - 0.5);
        ans += adnum;
        d = (N + 1.0) * d / N + (5.0 * x) / (2.0 * N);
        x = (1.0 + (2.0 / N)) * x;
        N--;
    }
    printf("%.20lf\n", ans);
    return 0;
}
// END-OF-CODE