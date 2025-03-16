#include <stdio.h>

int main() {
    int n, m;

    // Read an integer n from the user input
    scanf("%d", &n);

    // Print the value of n
    printf("%d ", n);

    // Initialize a variable m with the value of n
    m = n;

    // Enter a loop that runs from n-1 down to 1
    for (int i = n - 1; i > 0; i--) {
        // Check if m is divisible by i
        if (m % i == 0) {
            // If m is divisible by i, print i and update m to i
            printf("%d ", i);
            m = i;
        }
    }

    return 0;
}
