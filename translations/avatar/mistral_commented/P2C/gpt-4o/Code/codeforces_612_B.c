#include <stdio.h>
#include <stdlib.h>

int main() {
    // Take an integer 'n' as input
    int n;
    scanf("%d", &n);

    // Initialize a list 'a' of 'n' integers by taking input
    int *a = (int *)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    // Initialize an empty list 'b' of length 'n'
    int *b = (int *)malloc(n * sizeof(int));

    // Assign indices to 'b' based on the values in 'a'
    for (int i = 0; i < n; i++) {
        // Assign index 'i' to the position 'a[i] - 1' in list 'b'
        b[a[i] - 1] = i;
    }

    // Initialize a variable 'res' to 0
    int res = 0;

    // Calculate the absolute difference between consecutive indices in 'b' and sum them up
    for (int i = 1; i < n; i++) {
        // Add the absolute difference between indices 'i' and 'i-1' to 'res'
        res += abs(b[i] - b[i - 1]);
    }

    // Print the final result 'res'
    printf("%d\n", res);

    // Free allocated memory
    free(a);
    free(b);

    return 0;
}

// <END-OF-CODE>
