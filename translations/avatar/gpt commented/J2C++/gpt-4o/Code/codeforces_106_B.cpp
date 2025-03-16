#include <iostream>
#include <vector>
#include <limits>

using namespace std;

int main() {
    // Create a vector to store the input values
    int n;
    cin >> n; // Read the number of entries
    vector<vector<int>> vec(n, vector<int>(4)); // 2D vector to store the input values

    // Read input values into the 2D vector
    for (int i = 0; i < n; i++) {
        cin >> vec[i][0]; // Read first value
        cin >> vec[i][1]; // Read second value
        cin >> vec[i][2]; // Read third value
        cin >> vec[i][3]; // Read price
    }

    // Initialize variables to track the best option
    int ans = 500; // Default answer if no valid option is found
    int ansprice = numeric_limits<int>::max(); // Set a high initial price

    // Iterate through each entry to find the best option
    for (int i = 0; i < n; i++) {
        bool dominated = false; // Flag to check if the current entry is not dominated

        // Check if the current entry is dominated by any other entry
        for (int j = 0; j < n; j++) {
            if (vec[i][0] < vec[j][0] && vec[i][1] < vec[j][1] && vec[i][2] < vec[j][2]) {
                dominated = true; // Set flag to true if dominated
                break; // No need to check further
            }
        }

        // If the current entry is not dominated, check its price
        if (!dominated) {
            if (vec[i][3] < ansprice) {
                ansprice = vec[i][3]; // Update the best price found
                ans = i + 1; // Update the answer with the current index (1-based)
            }
        }
    }

    // Output the result
    cout << ans << endl; // Print the answer
    return 0; // End of the program
}

// <END-OF-CODE>
