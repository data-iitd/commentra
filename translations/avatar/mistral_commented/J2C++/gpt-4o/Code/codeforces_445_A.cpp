#include <iostream>
#include <vector>
#include <string>

using namespace std;

// Main function as the entry point of the C++ application
int main() {
    // Read the first line of input
    string line;
    getline(cin, line);
    
    // Split the input line into two integers n and m
    int n, m;
    sscanf(line.c_str(), "%d %d", &n, &m);

    // Create a vector to store the processed strings
    vector<string> ans(n);

    // Iterate through each string in the input
    for (int i = 0; i < n; i++) {
        getline(cin, line); // Read a string from the input
        string temp; // Initialize an empty string to build the result

        // Iterate through each character in the string
        for (int j = 0; j < m; j++) {
            if (line[j] == '-') { // If the character is a '-'
                temp += '-'; // Append a '-' character to temp
            } else {
                if ((i + j) % 2 == 1) { // If the index i + j is odd
                    temp += 'W'; // Append 'W' character to temp
                } else {
                    temp += 'B'; // Otherwise, append 'B' character to temp
                }
            }
        }

        // Store the final string in the ans vector using the index i
        ans[i] = temp;
    }

    // Iterate through each string in the ans vector and print it to the standard output stream
    for (int i = 0; i < n; i++) {
        cout << ans[i] << endl;
    }

    return 0;
}

// <END-OF-CODE>
