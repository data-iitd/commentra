#include <stdio.h>
#include <math.h>

int main() {
    int q;
    scanf("%d", &q); // Read the number of queries

    while (q-- > 0) {
        int n;
        scanf("%d", &n); // Read the number n for the current query
        long s = 0; // Initialize the sum variable s

        int x = (int)(log(n) / log(2)) + 1; // Calculate the position of the most significant bit of n

        s = -1 * (long)pow(2, x) + 2 + ((long)n * (n + 1)) / 2 - (long)pow(2, x);
        // Calculate s using arithmetic operations and power functions

        printf("%ld\n", s); // Print the result s for the current query
    }

    return 0;
}
