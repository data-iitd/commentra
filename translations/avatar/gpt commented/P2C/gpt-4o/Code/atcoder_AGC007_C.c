#include <stdio.h>

double main_function(int N, double d, double x) {
    double ret = 0.0;

    while (N) {
        ret += d + (N - 0.5) * x;

        d = d + (d / N) + (5 * x) / (2 * N);
        x += 2 * x / N;

        N--;
    }

    return ret;
}

int main() {
    int N;
    double d, x;

    // Read the input values for N, d, and x
    scanf("%d %lf %lf", &N, &d, &x);

    // Call the main function with the input values and print the result
    printf("%lf\n", main_function(N, d, x));

    return 0;
}

// <END-OF-CODE>
