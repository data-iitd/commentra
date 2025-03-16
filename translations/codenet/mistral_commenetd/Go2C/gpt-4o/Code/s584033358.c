// Import the standard input-output library
#include <stdio.h>

int main() {
    // Declare two integer variables "n" and "k"
    int n, k;

    // Read the values of "n" and "k" from the standard input
    scanf("%d %d", &n, &k);

    // Check if the value of "k" is less than or equal to the middle index of the slice "n"
    if (k <= (n + n % 2) / 2) {
        // If the condition is true, print "YES" to the standard output
        printf("YES\n");
    } else {
        // If the condition is false, print "NO" to the standard output
        printf("NO\n");
    }

    return 0;
}

// <END-OF-CODE>
