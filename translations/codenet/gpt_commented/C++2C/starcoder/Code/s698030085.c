#include <stdio.h>

int main(void) {
    // Declare two long long integer variables to hold the input values
    long long int a, b;

    // Read two integers from the standard input
    scanf("%lld %lld", &a, &b);

    // Check if the sum of a and b is even
    if ((a + b) % 2 == 0) {
        // If the sum is even, calculate and output the average
        printf("%lld\n", (a + b) / 2);
    } else {
        // If the sum is odd, output "IMPOSSIBLE"
        printf("IMPOSSIBLE\n");
    }
}
