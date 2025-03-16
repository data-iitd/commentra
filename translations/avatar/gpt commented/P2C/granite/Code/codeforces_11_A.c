
#include <stdio.h>

int main() {
    // Read two integers n and d from input
    int n, d;
    scanf("%d %d", &n, &d);

    // Initialize an empty list to store the elements
    int x[n];
    // Initialize variables to keep track of the total adjustments (m) and the current adjustment count (q)
    int m = 0, q = 0;

    // Read the elements of the list from input
    for (int i = 0; i < n; i++) {
        scanf("%d", &x[i]);
    }

    // Iterate through the list to compare adjacent elements
    for (int a = 0; a < n - 1; a++) {
        // Check if the current element is greater than or equal to the next element
        if (x[a] >= x[a + 1]) {
            // Calculate how many increments of d are needed to make x[a + 1] greater than x[a]
            q = (x[a] - x[a + 1]) / d + 1;
            // Update the total adjustments made
            m = m + q;
            // Adjust the next element by adding the necessary increments of d
            x[a + 1] = x[a + 1] + q * d;
        }
    }

    // Print the total number of adjustments made
    printf("%d", m);

    return 0;
}
