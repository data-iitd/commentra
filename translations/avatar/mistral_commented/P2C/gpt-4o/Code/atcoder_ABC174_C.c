#include <stdio.h>

int main() {
    // Read an integer from standard input
    int k;
    scanf("%d", &k);

    // Initialize a variable t to 0
    int t = 0;

    // Loop from 1 to k
    for (int i = 1; i <= k; i++) {
        // Calculate the value of t using the current value of i and k
        t = ( (t % k) * 10 + 7 ) % k;

        // Check if t is a multiple of k
        if (t == 0) {
            // Print the value of i and break out of the loop
            printf("%d\n", i);
            return 0; // Exit the program
        }
    }

    // If the loop completes without finding a multiple of k, print -1
    printf("-1\n");
    return 0; // Exit the program
}

// <END-OF-CODE>
