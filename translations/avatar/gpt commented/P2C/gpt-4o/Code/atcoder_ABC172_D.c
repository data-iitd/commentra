#include <stdio.h>

// Function to read an integer from standard input
int read_int() {
    int x;
    scanf("%d", &x);
    return x;
}

int main() {
    // Read the integer N from input
    int N = read_int();

    // Initialize the answer variable to accumulate the result
    long long ans = 0;

    // Loop through each integer from 1 to N (inclusive)
    for (int i = 1; i <= N; i++) {
        // Calculate the contribution of the current integer i to the answer
        ans += (long long)i * (N / i) * (N / i + 1) / 2;
    }

    // Print the final result
    printf("%lld\n", ans);

    return 0;
}

// <END-OF-CODE>
