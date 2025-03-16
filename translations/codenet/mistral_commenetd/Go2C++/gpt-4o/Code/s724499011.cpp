#include <iostream>
#include <vector>

using namespace std;

int main() {
    // Initialize variables
    int n;
    cin >> n; // Read the number of elements in the string 's'
    string s;
    cin >> s; // Read the string 's'
    vector<int> ns(n); // Create a vector 'ns' of length 'n' to store the color index for each character in 's'

    // Read the string 's' into 'ns'
    for (int i = 0; i < n; i++) {
        // Assign color index to 'ns' based on the character in 's'
        switch (s[i]) {
            case 'R':
                ns[i] = 0;
                break;
            case 'G':
                ns[i] = 1;
                break;
            case 'B':
                ns[i] = 2;
                break;
        }
    }

    // Initialize 'rgb' vector with zeros
    vector<vector<int>> rgb(n + 1, vector<int>(3, 0)); // Create a 2D vector 'rgb' initialized to zero
    for (int i = 1; i <= n; i++) {
        // Initialize each inner row of 'rgb' vector with values from the previous row
        for (int j = 0; j < 3; j++) {
            rgb[i][j] = rgb[i - 1][j]; // Copy values from the previous row
        }
        // Increment the value of the cell in the current row and column based on the color index of the previous character
        rgb[i][ns[i - 1]]++;
    }

    // Calculate the sum of differences between adjacent rows in 'rgb' vector
    int sum = 0;
    for (int i = 0; i < n - 2; i++) {
        for (int j = i + 1; j < n - 1; j++) {
            // Check if the characters in the current and next indices have different colors
            if (ns[i] != ns[j]) {
                // Calculate the total difference between the corresponding cells in the 'rgb' vector
                int tn = 3 - ns[i] - ns[j];
                sum += rgb[n][tn]; // Get the total RGB value of the last cell in the last row with the complementary color
                sum -= rgb[j + 1][tn]; // Subtract the total RGB value of the first cell in the next row with the complementary color

                // Check if there is a character with the same color index between the current and next indices
                int k = 2 * j - i;
                if (k < n && ns[k] == tn) {
                    sum--; // Decrease the sum if there is a character with the same color index between the current and next indices
                }
            }
        }
    }

    // Print the final result
    cout << sum << endl;
    // End of the code
}
