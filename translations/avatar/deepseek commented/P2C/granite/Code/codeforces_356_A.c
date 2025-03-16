

#include <stdio.h>

int main() {
    int n, m, l, r, x, t, next_val;
    scanf("%d %d", &n, &m); // Reading the number of elements and number of queries
    int out[n], comp[n]; // Initializing the output and comparison arrays
    for (int i = 0; i < n; i++) {
        out[i] = 0; // Initializing the output array with zeros
        comp[i] = i + 2; // Initializing the comparison array with values from 2 to n+1
    }
    for (int i = 0; i < m; i++) {
        scanf("%d %d %d", &l, &r, &x); // Reading the query parameters
        t = l;
        while (t <= r) {
            next_val = comp[t - 1]; // Getting the next value to compare
            if (out[t - 1] == 0 && t!= x) { // Checking if the current position should be updated
                out[t - 1] = x; // Updating the output array
            }
            comp[t - 1] = r + 1; // Updating the comparison array based on the condition
            if (t >= x) {
                comp[t - 1] = x;
            }
            t = next_val; // Moving to the next position in the range
        }
    }
    for (int i = 0; i < n; i++) {
        printf("%d ", out[i]); // Outputting the final result
    }
    return 0;
}
