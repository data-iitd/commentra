#include <stdio.h>
#include <stdlib.h>

int main() {
    // Read two integers n and m from the input
    int n, m;
    scanf("%d %d", &n, &m);

    // Calculate the number of '-' symbols in the input string
    int sa = 0;
    for (int i = 0; i < n; i++) {
        char c;
        scanf("%c", &c);
        if (c == '-') {
            sa++;
        }
    }

    // Ensure the number of '-' symbols is valid
    sa = min(n - sa, sa);

    // Perform each operation as described in the problem statement
    for (int i = 0; i < m; i++) {
        // Read two integers a and b from the input
        int a, b;
        scanf("%d %d", &a, &b);

        // Calculate the difference between b and a
        b -= a;

        // Check if the difference is valid based on the number of '-' symbols
        if (b % 2 == 0 || b > sa << 1) {
            // If the difference is valid, print '1'
            printf("1\n");
        } else {
            // If the difference is not valid, print '0'
            printf("0\n");
        }
    }

    // Print the final result by joining all the strings in the'ss' list with an empty string as separator
    return 0;
}
