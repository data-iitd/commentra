#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
    // Read the first line of input and split it into two integers n and m
    int n, m;
    cin >> n >> m;
    cin.ignore(); // To ignore the newline character after reading integers

    // Initialize a vector to hold the resulting strings
    vector<string> ans(n);

    // Loop through each of the n lines of input
    for (int i = 0; i < n; i++) {
        // Read the current line of input
        string str;
        getline(cin, str);

        // Create a string to construct the output for the current line
        string temp = "";

        // Loop through each character in the current line
        for (int j = 0; j < m; j++) {
            // Check if the character is a '-'
            if (str[j] == '-') {
                // Append '-' to the string if it is
                temp += "-";
            } else {
                // If the character is not '-', determine whether to append 'W' or 'B'
                if ((i + j) % 2 == 1) {
                    temp += "W"; // Append 'W' for odd indices
                } else {
                    temp += "B"; // Append 'B' for even indices
                }
            }
        }
        // Store the constructed string in the ans vector
        ans[i] = temp;
    }

    // Output the resulting strings line by line
    for (int i = 0; i < n; i++) {
        cout << ans[i] << endl;
    }

    return 0;
}

// <END-OF-CODE>
