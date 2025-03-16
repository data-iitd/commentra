
#include <stdio.h> // Include the standard input/output library
#include <limits.h> // Include the limits library for maximum integer value

int main() {
    int n, m, x, min = INT_MAX, a[10][11], status[10], res[11];
    scanf("%d%d%d", &n, &m, &x); // Read the number of ingredients, nutrient types, and minimum requirement
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= m; j++) {
            scanf("%d", &a[i][j]); // Read the nutrient amounts for each ingredient
        }
    }
    for (int i = 0; i < (1 << n); i++) {
        for (int j = 0; j < n; j++) {
            status[j] = (i >> j) & 1; // Generate all possible combinations of ingredients
        }
        for (int j = 0; j <= m; j++) {
            res[j] = 0; // Initialize the total nutrient amounts for the current combination
        }
        for (int j = 0; j < n; j++) {
            if (status[j] == 1) { // Add the nutrient amounts of included ingredients
                for (int k = 0; k <= m; k++) {
                    res[k] += a[j][k];
                }
            }
        }
        bool flag = true; // Check if the current combination meets the requirement
        for (int j = 1; j <= m; j++) {
            if (res[j] < x) { // Check if the nutrient requirement is met
                flag = false;
                break;
            }
        }
        if (flag) {
            min = (min < res[0]? min : res[0]); // Update the minimum cost if the requirement is met
        }
    }
    if (min == INT_MAX) {
        printf("-1\n"); // Output -1 if no combination meets the requirement
    } else {
        printf("%d\n", min); // Output the minimum cost if a valid combination is found
    }
    return 0;
}
