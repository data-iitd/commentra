#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, m;
    scanf("%d %d", &n, &m); // Reading the number of elements and number of queries

    int *out = (int *)calloc(n, sizeof(int)); // Initializing the output list with zeros
    int *comp = (int *)malloc(n * sizeof(int)); // Allocating memory for the comparison list

    // Initializing the comparison list with values from 2 to n+1
    for (int i = 0; i < n; i++) {
        comp[i] = i + 2;
    }

    // Processing each query
    for (int i = 0; i < m; i++) {
        int l, r, x;
        scanf("%d %d %d", &l, &r, &x); // Reading the query parameters
        int t = l;

        while (t <= r) {
            int next_val = comp[t - 1]; // Getting the next value to compare
            if (out[t - 1] == 0 && t != x) { // Checking if the current position should be updated
                out[t - 1] = x; // Updating the output list
            }
            comp[t - 1] = (t >= x) ? (r + 1) : x; // Updating the comparison list based on the condition
            t = next_val; // Moving to the next position in the range
        }
    }

    // Outputting the final result
    for (int i = 0; i < n; i++) {
        printf("%d ", out[i]);
    }
    printf("\n");

    // Free allocated memory
    free(out);
    free(comp);

    return 0;
} // <END-OF-CODE>
