#include <stdio.h>

int main() {
    // Read input: two integers n and k
    int n, k;
    scanf("%d %d", &n, &k);

    // Initialize variable x to 0
    int x = 0;

    // Check if k is valid based on the condition
    if (k <= (n * n) / 2 || k <= (n * n) - (n * n) / 2) {
        // If k is valid, print 'YES'
        printf("YES\n");

        // Iterate through rows and columns of the grid
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                // Check if current position (i, j) is valid based on the condition
                if (i % 2 == j % 2 && x < k) {
                    // If valid, print 'L' and increment x
                    printf("L");
                    x++;
                } else {
                    // If not valid, print 'S'
                    printf("S");
                }
            }
            // Move to the next line after completing a row
            printf("\n");
        }
    } else {
        // If k is not valid, print 'NO'
        printf("NO\n");
    }

    return 0;
}

// <END-OF-CODE>
