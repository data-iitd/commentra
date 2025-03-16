#include <stdio.h>
#include <stdlib.h>

// Main function is the entry point of the C application
int main() {
    // Read the number of requests and preemptions from the input
    int n, m;
    scanf("%d %d", &n, &m);

    // Allocate memory for request and preemption arrays
    int *req = (int *)malloc(n * sizeof(int));
    int *pre = (int *)malloc(m * sizeof(int));

    // Read request indices and store them in the array
    for (int i = 0; i < n; i++) {
        scanf("%d", &req[i]);
        // Comment: Read and store request index i
    }

    // Read preemption indices and store them in the array
    for (int i = 0; i < m; i++) {
        scanf("%d", &pre[i]);
        // Comment: Read and store preemption index i
    }

    // Initialize index variables for requests and preemptions
    int i = n - 1;
    int j = m - 1;

    // Initialize answer variable
    int ans = 0;

    // While there are still requests and preemptions to compare
    while (i >= 0 && j >= 0) {
        // If the current request can preempt the current preemption
        if (req[i] > pre[j]) {
            // Increment answer variable
            ans++;
        } else {
            // Decrement preemption index
            j--;
        }
        // Decrement request index
        i--;
    }

    // Print the answer and the number of remaining requests
    printf("%d\n", ans + i + 1);

    // Free allocated memory
    free(req);
    free(pre);

    return 0;
}

// <END-OF-CODE>
