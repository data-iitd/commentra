#include <stdio.h>
#include <stdlib.h>
<<<<<<< HEAD
#include <math.h>
=======
>>>>>>> 98c87cb78a (data updated)

int main() {
    // Read the values for R, G, B, and N from standard input
    int R, G, B, N;
    scanf("%d %d %d %d", &R, &G, &B, &N);

    int ans = 0; // Variable to store the count of valid combinations

    // Iterate over possible counts of red items (x)
    for (int x = 0; x <= N; x++) {
        // Iterate over possible counts of green items (y)
        for (int y = 0; y <= N; y++) {
            // Calculate the remaining items after choosing x red and y green
            int tmp = N - R * x - G * y;
            // Check if the remaining items can be fully represented by blue items
            if (tmp >= 0 && tmp % B == 0) {
                ans++; // Increment the count of valid combinations
            }
        }
    }

    // Output the total count of valid combinations
    printf("%d\n", ans);

    return 0;
}

// <END-OF-CODE>
