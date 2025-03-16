#include <stdio.h>

int main() {
    int n;
    long long ans = 0;

    // Read an integer input from the user
    scanf("%d", &n);

    // Loop through each integer from 1 to n (inclusive)
    for (int i = 1; i < n + 1; i++) {
        // Calculate the contribution of the current integer i to the result
        // This involves multiplying i by the number of times i fits into n
        // and summing up the series of numbers from 1 to (n / i)
        ans += (long long)i * ((long long)n / (long long)i) * (((long long)n / (long long)i) + 1) / 2;
    }

    // Output the final result
    printf("%lld\n", ans);

    return 0;
}
