#include <iostream>
#include <unordered_map>
#include <vector>
#include <fstream>

using namespace std;

// Function to read the next integer from the input stream.
int getNextInt(istream &input) {
    int value;
    input >> value;
    return value;
}

int main(int argc, char *argv[]) {
    // Set the input source to standard input; if a file is provided as an argument, open that file.
    istream *input = &cin;
    if (argc > 1) {
        ifstream file(argv[1]);
        input = &file;
    }

    // Read the first two integers, n and m, from the input.
    int n = getNextInt(*input);
    int m = getNextInt(*input);

    // Initialize a map to store the positions that are blocked (not allowed).
    unordered_map<int, int> blocked;
    for (int i = 0; i < m; i++) {
        blocked[getNextInt(*input)] = 1;
    }

    // Create a dynamic programming array to store the number of ways to reach each position.
    vector<int> dp(n + 1, 0);
    dp[0] = 1; // Base case: There is one way to be at the starting position (doing nothing).

    // Iterate through each position from 0 to n.
    for (int i = 0; i < n; i++) {
        // Check the next two positions (i+1 and i+2) to see if they can be reached.
        for (int ii = 1; ii <= 2 && i + ii <= n; ii++) {
            if (blocked.find(i + ii) != blocked.end()) {
                continue; // If blocked, skip to the next iteration.
            }
            // Update the number of ways to reach position i+ii based on the current position i.
            dp[i + ii] = (dp[i + ii] + dp[i]) % 1000000007; // Ensure the result stays within the modulo limit.
        }
    }

    // Output the total number of ways to reach position n.
    cout << dp[n] << endl;

    return 0;
}

// <END-OF-CODE>
