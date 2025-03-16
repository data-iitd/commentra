#include <stdio.h>

int main() {
    // Read input as two integers n and m
    int n, m;
    scanf("%d %d", &n, &m);

    // Check if both n and m are less than 1
    if (n < 1) {
        // If yes, check if m is also less than 1
        if (m < 1) {
            // Print n and m and exit the program
            printf("%d %d\n", n, m);
            return 0;
        }
        // If not, print "Impossible" and exit the program
        printf("Impossible\n");
        return 0;
    }

    // Check if m is greater than n
    if (m > n) {
        // If yes, calculate the minimum and maximum values
        int min = m;
        int max = n + m - 1;
        // Print the minimum and maximum values
        printf("%d %d\n", min, max);
    }

    // If m is less than or equal to n
    if (m <= n) {
        // Calculate the minimum and maximum values
        int min = n;
        int max = n + m - 1;
        // If m is 0, adjust the maximum value accordingly
        if (m == 0) {
            max = n;
        }
        // Print the minimum and maximum values
        printf("%d %d\n", min, max);
    }

    return 0;
}

// <END-OF-CODE>
