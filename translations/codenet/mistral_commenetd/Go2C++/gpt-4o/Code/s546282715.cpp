#include <iostream>
#include <unordered_map>
#include <vector>
#include <fstream>

using namespace std;

// Function to read the next integer from the input stream
int getNextInt(istream &input) {
    int i;
    input >> i;
    return i;
}

// Main function
int main(int argc, char *argv[]) {
    // Open the standard input file if the command line argument is provided
    ifstream fp;
    if (argc > 1) {
        fp.open(argv[1]);
        if (!fp) {
            cerr << "Error opening file." << endl;
            return 1;
        }
    } else {
        fp.open("/dev/stdin");
    }

    // Read the first two integers from the input
    int n = getNextInt(fp);
    int m = getNextInt(fp);

    // Initialize an associative array to store the elements
    unordered_map<int, int> aa;
    // Read m elements and store them in the associative array
    for (int i = 0; i < m; i++) {
        aa[getNextInt(fp)] = 1;
    }

    // Initialize a vector of length n+1 for dynamic programming
    vector<int> dp(n + 1, 0);
    // Initialize the first element of the vector
    dp[0] = 1;

    // Iterate through the array from index 0 to n-1
    for (int i = 0; i < n; i++) {
        // Iterate through the prefix sum from i to i+2
        for (int ii = 1; ii <= 2 && i + ii <= n; ii++) {
            // Skip if the current index and its sum are already present in the associative array
            if (aa.find(i + ii) != aa.end()) {
                continue;
            }
            // Calculate the dynamic programming value for the current index
            dp[i + ii] = (dp[i + ii] + dp[i]) % 1000000007;
        }
    }

    // Print the final answer
    cout << dp[n] << endl;

    // Close the file if it was opened
    if (fp.is_open()) {
        fp.close();
    }

    return 0;
}

// <END-OF-CODE>
