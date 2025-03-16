#include <stdio.h>
#include <math.h>

int main() {
    // Take an integer input from the user and assign it to the variable n
    int n;
    scanf("%d", &n);

    // Initialize a counter variable x to 1
    int x = 1;

    // While loop starts
    while (1) {
        // Check if the log base 2 of n is an integer yet
        if (log2(n) == (int)log2(n)) {
            break;
        }

        // Increment the counter variable x by 1
        x += 1;

        // Update the value of n by subtracting 2 raised to the power of the current log base 2 of n
        n -= (int)pow(2, (int)log2(n));
    }

    // Print the output value of x
    printf("%d\n", x);

    return 0;
}

// <END-OF-CODE>
