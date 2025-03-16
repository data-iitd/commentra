#include <stdio.h>
#include <stdlib.h>

int main() {
    // Read an integer input which represents the number of elements
    int n;
    scanf("%d", &n);

    // Allocate memory for the array of integers
    int *r = (int *)malloc(n * sizeof(int));

    // Read a line of input and store it in the array
    for (int i = 0; i < n; i++) {
        scanf("%d", &r[i]);
    }

    // Initialize the answer with the absolute value of the first element in the array
    long long ans = abs(r[0]);

    // Iterate through the array starting from the second element
    for (int i = 1; i < n; i++) {
        // Add the absolute difference between the current element and the previous element to the answer
        ans += abs(r[i] - r[i - 1]);
    }

    // Print the final computed answer
    printf("%lld\n", ans);

    // Free the allocated memory
    free(r);

    return 0;
}

// <END-OF-CODE>
