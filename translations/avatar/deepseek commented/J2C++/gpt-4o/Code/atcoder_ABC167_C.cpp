#include <iostream>
#include <vector>
#include <cmath>
#include <limits>

using namespace std;

int main() {
    int n, m, x;
    cin >> n >> m >> x; // Reading the number of ingredients, nutrient types, and minimum requirement
    int minCost = numeric_limits<int>::max(); // Initializing the minimum cost to a large value
    vector<vector<int>> a(n, vector<int>(m + 1)); // Initializing the 2D vector to store nutrient amounts

    // Filling the vector with nutrient amounts for each ingredient
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= m; j++) {
            cin >> a[i][j];
        }
    }

    // Generating all possible combinations of ingredients
    for (int i = 0; i < (1 << n); i++) {
        vector<int> status(n, 0); // Vector to store the status of each ingredient in the combination
        for (int j = 0; j < n; j++) {
            if ((1 & (i >> j)) == 1) { // Checking if the j-th ingredient is included
                status[j] = 1;
            }
        }
        vector<int> res(m + 1, 0); // Vector to store the total nutrient amounts for the current combination
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
            minCost = min(minCost, res[0]); // Updating the minimum cost if the requirement is met
        }
    }

    // Outputting the result
    if (minCost == numeric_limits<int>::max()) {
        cout << -1 << endl; // Outputting -1 if no combination meets the requirement
    } else {
        cout << minCost << endl; // Outputting the minimum cost if a valid combination is found
    }

    return 0;
}

// <END-OF-CODE>
