
#include <stdio.h>
#include <stdlib.h>

int main() {
    // Create a Scanner object to read input from the console
    int n, m;
    scanf("%d %d", &n, &m);

    // Initialize arrays to store the required items and the available items
    int req[n], pre[m];

    // Read the required items from the input and store them in the req array
    for (int i = 0; i < n; i++) {
        scanf("%d", &req[i]);
    }

    // Read the available items from the input and store them in the pre array
    for (int i = 0; i < m; i++) {
        scanf("%d", &pre[i]);
    }

    // Initialize pointers for the required items (i) and available items (j)
    int i = n - 1, j = m - 1;

    // Variable to count how many required items can be satisfied
    int ans = 0;

    // Compare the required items with the available items from the end of both arrays
    while (i >= 0 && j >= 0) {
        // If the current required item is greater than the current available item
        if (req[i] > pre[j]) {
            // Increment the count of satisfied items
            ans++;
        } else {
            // Move to the next available item if the current one cannot satisfy the requirement
            j--;
        }
        // Move to the next required item
        i--;
    }

    // Print the total number of satisfied items plus the remaining unsatisfied required items
    printf("%d\n", ans + i + 1);

    return 0;
}
