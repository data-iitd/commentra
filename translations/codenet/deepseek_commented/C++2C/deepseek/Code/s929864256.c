#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int main() {
    long long a, b;
    scanf("%lld %lld", &a, &b); // Read two long long integers from standard input

    // Compute the maximum value among a+b, a-b, and a*b
    long long max_value = a + b;
    if (a - b > max_value) {
        max_value = a - b;
    }
    if (a * b > max_value) {
        max_value = a * b;
    }
    printf("%lld\n", max_value); // Print the maximum value

    return 0; // Return 0 indicating successful execution
}
