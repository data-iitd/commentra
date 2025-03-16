#include <stdio.h>

int main() {
    int n, i;

    // Ask the user to input an integer value
    scanf("%d", &n);

    // Initialize a variable i and set its value to n
    for (i = n; i > 0; i--) {
        // Check if n is divisible by the current value of i
        if (n % i == 0) {
            // If the condition is true, update the value of n to i
            n = i;
            // Print the current value of i
            printf("%d ", i);
        }
    }

    return 0;
}
