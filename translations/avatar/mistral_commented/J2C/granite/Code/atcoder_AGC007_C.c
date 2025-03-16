

#include <stdio.h>
#include <math.h>

int main() {
    double N, d, x, ans = 0.0;
    double adnum;

    // Reading input values from the user
    scanf("%lf %lf %lf", &N, &d, &x);

    // Calculating the answer using the given formula
    while (N > 0.5) {
        adnum = d + x * (N - 0.5); // Calculating the next term of the sum
        ans += adnum; // Adding the next term to the answer

        // Updating the values of d and x for the next iteration
        d = (N + 1.0) * d / N + (5.0 * x) / (2.0 * N);
        x = (1.0 + (2.0 / N)) * x;

        --N; // Decreasing the value of N by 1 for the next iteration
    }

    // Printing the final answer with 20 decimal places
    printf("%.20lf\n", ans);

    return 0;
}
