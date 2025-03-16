#include <stdio.h>

double main_function(int N, double d, double x) {
    double ret = 0.0;
    while (N) {
        ret += d + (N - 0.5) * x;
        d = d + (d / N) + (5 * x) / (2 * N);
        x += 2 * x / N;
        N -= 1;
    }
    return ret;
}

int main() {
    int N;
    double d, x;
    scanf("%d %lf %lf", &N, &d, &x);
    printf("%lf\n", main_function(N, d, x));
    return 0;
}

// <END-OF-CODE>
