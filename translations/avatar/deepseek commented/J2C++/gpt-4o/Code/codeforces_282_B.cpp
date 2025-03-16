#include <iostream>
#include <vector>
#include <cmath>
#include <string>

using namespace std;

int main() {
    int n;
    cin >> n; // Read the number of elements
    vector<char> ch; // Declare a vector to store the result
    int s1 = 0, s2 = 0; // Initialize sums for two paths
    int flag = 0; // Flag for invalid configuration

    // Loop to read inputs and decide paths
    for (int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y; // Read the next integers for path 'x' and 'y'
        int temp1 = s1 + x; // Calculate temporary sum for path 'x'
        int temp2 = s2 + y; // Calculate temporary sum for path 'y'

        // Check if adding to path 'x' or 'y' is valid
        if (abs(temp1 - s2) <= 500) {
            s1 += x; // Update sum for path 'x'
            ch.push_back('A'); // Append 'A' to the result vector
            continue; // Continue to the next iteration
        }
        if (abs(temp2 - s1) <= 500) {
            s2 += y; // Update sum for path 'y'
            ch.push_back('G'); // Append 'G' to the result vector
            continue; // Continue to the next iteration
        }
        flag = 1; // Set flag to indicate invalid configuration
        break; // Break out of the loop
    }

    // Handle the result based on the flag
    if (flag == 1)
        cout << -1 << endl; // Print -1 if configuration is invalid
    else {
        string ans(ch.begin(), ch.end()); // Convert vector to string
        cout << ans << endl; // Print the result string
    }

    return 0;
}

// <END-OF-CODE>
