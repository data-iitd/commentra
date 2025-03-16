#include <stdio.h>
#include <limits.h>
#include <math.h>

int main() {
    int n, m, x;
    scanf("%d %d %d", &n, &m, &x); // Reading the number of ingredients, nutrient types, and minimum requirement
    int min = INT_MAX; // Initializing the minimum cost to a large value
    int a[n][m + 1]; // Initializing the 2D array to store nutrient amounts

    // Filling the array with nutrient amounts for each ingredient
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= m; j++) {
            scanf("%d", &a[i][j]);
        }
    }

    // Generating all possible combinations of ingredients
    for (int i = 0; i < (1 << n); i++) {
        int status[n]; // Array to store the status of each ingredient in the combination
        for (int j = 0; j < n; j++) {
            status[j] = (i & (1 << j)) ? 1 : 0; // Checking if the j-th ingredient is included
        }
        int res[m + 1]; // Array to store the total nutrient amounts for the current combination
        for (int j = 0; j <= m; j++) {
            res[j] = 0; // Initialize the nutrient amounts to 0
        }
        for (int j = 0; j < n; j++) {
            if (status[j] == 1) { // Adding the nutrient amounts of included ingredients
                for (int k = 0; k <= m; k++) {
                    res[k] += a[j][k];
                }
            }
        }
        int flag = 1; // Flag to check if the current combination meets the requirement
        for (int j = 1; j <= m; j++) {
            if (res[j] < x) { // Checking if the nutrient requirement is met
                flag = 0;
                break;
            }
        }
        if (flag) {
            min = (res[0] < min) ? res[0] : min; // Updating the minimum cost if the requirement is met
        }
    }

    // Outputting the result
    if (min == INT_MAX) {
        printf("-1\n"); // Outputting -1 if no combination meets the requirement
    } else {
        printf("%d\n", min); // Outputting the minimum cost if a valid combination is found
    }

    return 0;
}
