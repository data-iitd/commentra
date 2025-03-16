#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Function to return the minimum of two integers
int min(int a, int b) {
    return (a <= b) ? a : b;
}

// Function to process the chain of colors and return the count of remaining colors
int Chain(vector<int>& b, int n) {
    int count; // To count the number of consecutive colors
    int color; // To store the current color being processed
    vector<int> a = b; // Copy input vector b to vector a

    // Loop through the array to find sequences of four identical colors
    for (int i = 0; i < n - 4; i++) {
        // Check if there are four consecutive identical colors
        if (a[i] != 0 && a[i] == a[i + 1] && a[i] == a[i + 2] && a[i] == a[i + 3]) {
            // Initialize count and set the current color
            count = 0;
            color = a[i];

            // Set the found colors to zero and count them
            for (int j = i; a[j] == color; j++) {
                a[j] = 0; // Remove the color by setting it to zero
                count++; // Increment the count of removed colors
            }

            // Shift the remaining colors to fill the gap left by removed colors
            for (int j = 0; i + j + count < 10000; j++) {
                a[i + j] = a[i + j + count];
                a[i + j + count] = 0; // Set the shifted out colors to zero
            }

            // Reset the index to start checking from the beginning
            i = -1; // Set to -1 because it will be incremented to 0 in the next iteration
        }
    }

    // Count the number of remaining colors in the array
    count = 0;
    while (count < a.size() && a[count] != 0) {
        count++;
    }

    // Check if there are exactly four of the same color left at the start
    if (count == 4 && a[0] == a[1] && a[0] == a[2] && a[0] == a[3]) {
        return 0; // Return 0 if four identical colors remain
    }

    return count; // Return the count of remaining colors
}

// Main function to execute the program
int main() {
    int n; // Number of colors
    int ans; // Variable to hold the answer
    vector<int> a(10000); // Vector to hold the colors

    // Infinite loop to process multiple test cases
    while (true) {
        // Initialize the vector to zero
        fill(a.begin(), a.end(), 0);

        // Read the number of colors
        cin >> n;
        if (n == 0) {
            break; // Exit the loop if n is 0
        }
        ans = n; // Initialize ans with the number of colors

        // Read the colors into the vector
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }

        // Check for groups of four colors to replace
        for (int i = 0; i < n - 4; i++) {
            int count[3] = {0, 0, 0}; // Array to count occurrences of colors

            // Count occurrences of colors in the current window of four
            for (int j = i; j < i + 4; j++) {
                if (a[j] - 1 >= 0) {
                    count[a[j] - 1]++;
                }
            }

            int color = 0; // Reset color
            // Determine if any color appears at least three times
            for (int j = 0; j < 3; j++) {
                if (count[j] >= 3) {
                    color = j + 1; // Set the color to replace
                    break;
                }
            }

            // If a color is found to replace, perform the replacement
            if (color != 0) {
                for (int j = i; j < i + 4; j++) {
                    int buf = a[j]; // Temporary variable to hold the current color
                    a[j] = color; // Replace with the new color
                    ans = min(ans, Chain(a, n)); // Calculate the new answer
                    a[j] = buf; // Restore the original color
                }
            }
        }

        // Print the final answer for the current test case
        cout << ans << endl;
    }

    return 0; // Return success
}

// <END-OF-CODE>
