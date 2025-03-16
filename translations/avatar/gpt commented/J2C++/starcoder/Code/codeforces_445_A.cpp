#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
    // Read the first line of input and split it into an array of strings
    string line;
    getline(cin, line);
    vector<string> inp = split(line,'');

    // Parse the first two elements of the input array as integers n and m
    int n = stoi(inp[0]);
    int m = stoi(inp[1]);

    // Initialize an array to hold the resulting strings
    vector<string> ans(n);

    // Loop through each of the n lines of input
    for (int i = 0; i < n; i++) {
        // Read the current line of input
        getline(cin, line);

        // Create a StringBuilder to construct the output for the current line
        string temp = "";

        // Loop through each character in the current line
        for (int j = 0; j < m; j++) {
            // Check if the character is a '-'
            if (line[j] == '-') {
                // Append '-' to the StringBuilder if it is
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

        // Store the constructed string in the ans array
        ans[i] = temp;
    }

    // Output the resulting strings line by line
    for (int i = 0; i < n; i++) {
        cout << ans[i] << endl;
    }

    return 0;
}

