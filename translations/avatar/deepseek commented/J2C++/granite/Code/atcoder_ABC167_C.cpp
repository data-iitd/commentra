
#include <iostream> // Including the necessary libraries
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, m, x; // Declaring the variables for the number of ingredients, nutrient types, and minimum requirement
    cin >> n >> m >> x; // Reading the input values

    vector<vector<int>> a(n, vector<int>(m + 1)); // Initializing the 2D vector to store nutrient amounts

    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= m; j++) {
            cin >> a[i][j]; // Filling the vector with nutrient amounts for each ingredient
        }
    }

    int min = INT_MAX; // Initializing the minimum cost to a large value

    for (int i = 0; i < (1 << n); i++) { // Generating all possible combinations of ingredients
        vector<int> status(n); // Vector to store the status of each ingredient in the combination
        for (int j = 0; j < n; j++) {
            if ((1 & i >> j) == 1) { // Checking if the j-th ingredient is included
                status[j] = 1;
            }
        }
        vector<int> res(m + 1); // Vector to store the total nutrient amounts for the current combination
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

    if (min == INT_MAX) { // Outputting the result
        cout << -1 << endl;
    } else {
        cout << min << endl;
    }

    return 0; // Ending the program
}

