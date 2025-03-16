#include <iostream>
#include <fstream>
#include <unordered_map>
#include <vector>

using namespace std;

// Function to read the next integer from the input stream
int getNextInt(istream &input) {
    int value;
    input >> value;
    return value;
}

// Main function starts here
int main(int argc, char *argv[]) {
    // Determine the input source based on command-line arguments
    ifstream file;
    istream *input = &cin;
    if (argc > 1) {
        file.open(argv[1]);
        input = &file;
    }

    // Read the number of elements (n) and the number of restricted positions (m)
    int n = getNextInt(*input);
    int m = getNextInt(*input);

    // Create a map to store the restricted positions
    unordered_map<int, int> aa;
    for (int i = 0; i < m; i++) {
        aa[getNextInt(*input)] = 1;
    }

    // Initialize the dynamic programming array
    vector<int> dp(n + 1, 0);
    dp[0] = 1;

    // Fill the dynamic programming array based on restricted positions
    for (int i = 0; i < n; i++) {
        for (int ii = 1; ii <= 2 && i + ii <= n; ii++) {
            if (aa.find(i + ii) != aa.end()) {
                continue;
            }
            dp[i + ii] = (dp[i + ii] + dp[i]) % 1000000007;
        }
    }

    // Print the result
    cout << dp[n] << endl;

    // Close the file if it was opened
    if (file.is_open()) {
        file.close();
    }

    return 0;
}
// <END-OF-CODE>
