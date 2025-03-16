

#include <stdio.h>

int main() {
    // Initialize variables
    int n, m;
    // Read input from standard input
    scanf("%d %d", &n, &m);
    // Allocate memory for h array
    int h[n];
    // Read h array elements from standard input
    for (int i = 0; i < n; i++) {
        scanf("%d", &h[i]);
        // Comment for the loop that reads h array elements
        // from standard input
        // and stores them in the h array
    }
    // Initialize counter map
    int counter[n];
    // Read m query pairs from standard input
    for (int i = 0; i < m; i++) {
        int a, b;
        scanf("%d %d", &a, &b);
        // Check the condition for a and b
        if (h[a-1] < h[b-1]) {
            // Add a to the counter map if h[a-1] is smaller than h[b-1]
            counter[a-1]++;
        } else if (h[a-1] > h[b-1]) {
            // Add b to the counter map if h[a-1] is greater than h[b-1]
            counter[b-1]++;
        } else if (h[a-1] == h[b-1]) {
            // Add both a and b to the counter map if h[a-1] is equal to h[b-1]
            counter[a-1]++;
            counter[b-1]++;
        }
        // Comment for the loop that processes m query pairs
    }
    // Print the result
    int result = 0;
    for (int i = 0; i < n; i++) {
        if (counter[i] == 0) {
            result++;
        }
    }
    printf("%d\n", result);
    // Comment for the final print statement
}

