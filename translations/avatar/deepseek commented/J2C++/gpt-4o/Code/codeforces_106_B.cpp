#include <iostream>
#include <vector>
#include <limits>

using namespace std;

int main() {
    // Initialize input and output
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    // Read the number of elements
    int n;
    cin >> n;

    // Initialize a 2D vector to store the elements
    vector<vector<int>> vec(n, vector<int>(4));

    // Read the elements into the 2D vector
    for (int i = 0; i < n; i++) {
        cin >> vec[i][0];
        cin >> vec[i][1];
        cin >> vec[i][2];
        cin >> vec[i][3];
    }

    // Initialize variables to store the best index and its price
    int ans = 500;
    int ansprice = 20000;

    // Loop through each element to find the best one
    for (int i = 0; i < n; i++) {
        bool dominated = false; // Flag to check if the element is dominated

        // Compare the current element with every other element
        for (int j = 0; j < n; j++) {
            if (vec[i][0] < vec[j][0] && vec[i][1] < vec[j][1] && vec[i][2] < vec[j][2]) {
                dominated = true; // The element is dominated
                break; // No need to check further
            }
        }

        // If the element is not dominated, check its price
        if (!dominated) {
            if (vec[i][3] < ansprice) {
                ansprice = vec[i][3]; // Update the minimum price
                ans = i + 1; // Update the best index
            }
        }
    }

    // Output the index of the best element
    cout << ans << endl;

    return 0;
}

// <END-OF-CODE>
