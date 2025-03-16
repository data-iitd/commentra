#include <stdio.h>
#include <stdlib.h>

int main() {
    // Read the number of elements
    int N;
    scanf("%d", &N);

    // Allocate memory for the values and costs
    int *V = (int *)malloc(N * sizeof(int));
    int *C = (int *)malloc(N * sizeof(int));

    // Read the values into an array
    for (int i = 0; i < N; i++) {
        scanf("%d", &V[i]);
    }

    // Read the costs into an array
    for (int i = 0; i < N; i++) {
        scanf("%d", &C[i]);
    }

    // Initialize a variable to hold the total profit
    int ans = 0;

    // Iterate through each item
    for (int i = 0; i < N; i++) {
        // Check if the value is greater than the cost
        if (V[i] - C[i] > 0) {
            // Calculate the profit and add it to the total profit
            ans += (V[i] - C[i]);
        }
    }

    // Print the total profit
    printf("%d\n", ans);

    // Free allocated memory
    free(V);
    free(C);

    return 0;
}

// <END-OF-CODE>
