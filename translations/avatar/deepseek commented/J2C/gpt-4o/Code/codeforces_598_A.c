#include <stdio.h>
#include <math.h>

int main() {
    int q;
    scanf("%d", &q); // Read the number of queries

    while (q-- > 0) {
        int n;
        scanf("%d", &n); // Read the number n for the current query
        long s = 0; // Initialize the sum variable s

        int x = (int)(log(n) / log(2)); // Calculate the position of the most significant bit of n
        x++; // Increment x by 1

        s = -1 * (long)pow(2, x) + 2 + ((long)n * (long)(n + 1)) / 2 - (long)pow(2, x);
        // Calculate s using arithmetic operations and power functions

        printf("%ld\n", s); // Print the result s for the current query
    }
    return 0;
}

// <END-OF-CODE>
