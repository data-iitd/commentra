#include <stdio.h>
#include <stdlib.h>

// Function to compute the greatest common divisor (GCD) of two integers
int gcd(int a, int b) {
    // Ensure 'a' is the larger number for the algorithm
    if (a < b) {
        int temp = a;
        a = b;
        b = temp;
    }
    int r;
    // Apply the Euclidean algorithm to find the GCD
    while ((r = a % b) > 0) {
        a = b; // Update 'a' to 'b'
        b = r; // Update 'b' to the remainder
    }
    return b; // Return the GCD
}

int main() {
    int n; // Variable to store the number of integers
    scanf("%d", &n); // Read the number of integers from input

    int ans; // Variable to store the current GCD result
    scanf("%d", &ans); // Read the first integer and initialize 'ans' with it

    // Loop through the remaining integers to compute the GCD
    for (int i = 1; i < n; ++i) {
        int a; // Variable to store the current integer
        scanf("%d", &a); // Read the current integer from input
        ans = gcd(ans, a); // Update 'ans' with the GCD of 'ans' and 'a'
    }

    // Output the final GCD result
    printf("%d\n", ans);

    return 0; // Indicate that the program ended successfully
}
