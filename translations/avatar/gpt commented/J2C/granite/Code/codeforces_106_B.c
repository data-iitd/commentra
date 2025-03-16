
#include <stdio.h>

int main() {
    // Create a Scanner object for input and a PrintWriter for output
    int n;
    scanf("%d", &n);
    int vec[n][4];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 4; j++) {
            scanf("%d", &vec[i][j]);
        }
    }

    // Initialize variables to track the best option
    int ans = 500; // Default answer if no valid option is found
    int ansprice = 20000; // Set a high initial price

    // Iterate through each entry to find the best option
    for (int i = 0; i < n; i++) {
        int fl = 1; // Flag to check if the current entry is not dominated

        // Check if the current entry is dominated by any other entry
        for (int j = 0; j < n; j++) {
            if (vec[i][0] < vec[j][0] && vec[i][1] < vec[j][1] && vec[i][2] < vec[j][2]) {
                fl = 0; // Set flag to 0 if dominated
            }
        }

        // If the current entry is not dominated, check its price
        if (fl == 1) {
            if (vec[i][3] < ansprice) {
                ansprice = vec[i][3]; // Update the best price found
                ans = i + 1; // Update the answer with the current index (1-based)
            }
        }
    }

    // Output the result
    printf("%d\n", ans);

    return 0;
}
