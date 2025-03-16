#include <stdio.h>

int main() {
    // Declare variables for input
    int n, m;

    // Read two integers n and m from the input
    scanf("%d %d", &n, &m);

    // Check if n is zero
    if (n == 0) {
        // If m is not zero, print "Impossible" since we cannot form a valid output
        if (m != 0) {
            printf("Impossible\n");
        }
        // If m is also zero, print "0 0" as the valid output
        else {
            printf("0 0\n");
        }
        return 0;
    }

    // Check if m is less than or equal to n
    if (m <= n) {
        // If m is zero, set it to one to ensure valid output
        if (m == 0) {
            m = 1;
        }
        // Print n and the adjusted value of m
        printf("%d %d\n", n, (m + n - 1));
        return 0;
    }

    // If m is greater than n, print m and the adjusted value of m
    printf("%d %d\n", m, (m + n - 1));

    return 0;
}

// <END-OF-CODE>
