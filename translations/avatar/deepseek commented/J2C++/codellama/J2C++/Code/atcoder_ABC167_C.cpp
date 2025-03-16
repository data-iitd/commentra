#include <iostream>
#include <cmath>

using namespace std;

int main() {
    int n, m, x, min = INT_MAX; // Initializing the variables
    cin >> n >> m >> x; // Reading the input
    int a[n][m + 1]; // Initializing the 2D array to store nutrient amounts

    // Filling the array with nutrient amounts for each ingredient
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= m; j++) {
            cin >> a[i][j];
        }
    }

    // Generating all possible combinations of ingredients
    for (int i = 0; i < pow(2, n); i++) {
        int status[n]; // Array to store the status of each ingredient in the combination
        for (int j = 0; j < n; j++) {
            if ((1 & i >> j) == 1) { // Checking if the j-th ingredient is included
                status[j] = 1;
            }
        }
        int res[m + 1]; // Array to store the total nutrient amounts for the current combination
        for (int j = 0; j < n; j++) {
            if (status[j] == 1) { // Adding the nutrient amounts of included ingredients
                for (int k = 0; k <= m; k++) {
                    res[k] += a[j][k];
                }
            }
        }
        bool flag = true; // Flag to check if the current combination meets the requirement
        for (int j = 1; j <= m; j++) {
            if (res[j] < x) { // Checking if the nutrient requirement is met
                flag = false;
                break;
            }
        }
        if (flag) {
            min = min(min, res[0]); // Updating the minimum cost if the requirement is met
        }
    }

    // Outputting the result
    if (min == INT_MAX) {
        cout << -1 << endl; // Outputting -1 if no combination meets the requirement
    } else {
        cout << min << endl; // Outputting the minimum cost if a valid combination is found
    }

    return 0;
}

