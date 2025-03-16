
#include <iostream>
#include <string>
#include <cstdio>

using namespace std;

int main() {
    // Create a Scanner object to read input from the console
    // Read the integer n which represents the length of the string
    // Read the string s which contains characters 'R', 'G', and 'B'
    int n;
    string s;
    cin >> n >> s;

    // Initialize counters for each color
    long long rc = 0; // Counter for 'R'
    long long gc = 0; // Counter for 'G'
    long long bc = 0; // Counter for 'B'

    // Count the occurrences of each character in the string
    for (int i = 0; i < s.length(); i++) {
        if (s[i] == 'R') {
            rc++; // Increment red counter
        } else if (s[i] == 'G') {
            gc++; // Increment green counter
        } else {
            bc++; // Increment blue counter
        }
    }

    // Calculate the initial result based on the product of the counts
    long long result = rc * gc * bc;

    // Iterate through all pairs of indices (i, k) to check conditions
    for (int i = 1; i <= n; i++) {
        for (int k = i + 1; k <= n; k++) {
            // Check if the sum of indices is even
            if ((i + k) % 2 == 0) {
                // Get the characters at the current indices
                char is = s[i - 1];
                char ks = s[k - 1];
                char js = s[((i + k) / 2) - 1];

                // Check if all three characters are different
                if (is!= ks && ks!= js && js!= is) {
                    result--; // Decrease the result if the condition is met
                }
            }
        }
    }

    // Output the final result
    cout << result << endl;

    return 0;
}
