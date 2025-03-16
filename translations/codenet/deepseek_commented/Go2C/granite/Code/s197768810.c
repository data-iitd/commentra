
#include <stdio.h>
#include <stdlib.h>

int main() {
    // Set the scanner to read words instead of lines
    // (This step is not required in C as it reads words by default)

    // Read two integers n and m from the input
    int n, m;
    scanf("%d %d", &n, &m);

    // Initialize a slice to hold m integers
    int a[m];
    int sum = 0;

    // Read m integers into the slice a and calculate their sum
    for (int i = 0; i < m; i++) {
        scanf("%d", &a[i]);
        sum += a[i];
    }

    // Check if the sum of integers exceeds n
    if (sum > n) {
        // Print -1 if the sum exceeds n and exit
        printf("-1\n");
        return 0;
    }

    // Print the difference between n and the sum if it's within bounds
    printf("%d\n", n - sum);

    return 0;
}
