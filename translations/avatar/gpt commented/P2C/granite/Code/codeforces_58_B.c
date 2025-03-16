
#include <stdio.h>

int main() {
    int n;
    // Read an integer input from the user
    scanf("%d", &n);

    // Iterate from n down to 1
    for (int i = n; i > 0; i--) {
        // Check if i is a divisor of n
        if (n % i == 0) {
            // Update n to the current divisor i
            n = i;
            // Print the divisor followed by a space
            printf("%d ", i);
        }
    }
    // Print a newline character
    printf("\n");
    return 0;
}
