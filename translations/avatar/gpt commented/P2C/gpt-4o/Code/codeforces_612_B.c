#include <stdio.h>
#include <stdlib.h>

int main() {
    // Read the number of elements
    int n;
    scanf("%d", &n);

    // Read the elements into an array and convert them to integers
    int *a = (int *)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    // Initialize an array 'b' with zeros to store the positions of elements
    int *b = (int *)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        b[a[i] - 1] = i;  // Store the index of each element in 'b' based on its value in 'a'
    }

    // Initialize the result variable to accumulate the total distance
    long long res = 0;

    // Calculate the total distance between consecutive elements in 'b'
    for (int i = 1; i < n; i++) {
        res += abs(b[i] - b[i - 1]);  // Add the absolute difference of indices to the result
    }

    // Print the final result
    printf("%lld\n", res);

    // Free allocated memory
    free(a);
    free(b);

    return 0;
}

// <END-OF-CODE>
