#include <stdio.h>

int main() {
    int n, k; // Declare variables for number of elements and initial value of k
    scanf("%d", &n); // Read the number of elements in the sequence
    scanf("%d", &k); // Read the initial value of k

    int i = 1, req = 1; // Initialize i and req to 1

    // Loop continues as long as k - req is non-negative
    while (k - req >= 0) {
        if (k - req >= 0) {
            k = k - req; // Subtract req from k if k - req is non-negative
        } else {
            break; // Exit the loop if k - req is negative
        }
        i++; // Increment i
        if (i % n != 0) {
            req = i % n; // Update req to i % n if i % n is not zero
        } else {
            req = n; // Update req to n if i % n is zero
        }
    }

    printf("%d\n", k); // Print the final value of k
    return 0; // Return 0 to indicate successful completion
}

// <END-OF-CODE>
