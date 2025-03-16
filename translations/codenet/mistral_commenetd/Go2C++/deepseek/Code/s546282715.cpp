#include <iostream>
#include <sstream>
#include <vector>
#include <unordered_set>

using namespace std;

// Function to read the next word from the input stream
string getNextWord(istream& is) {
    string word;
    is >> word;
    return word;
}

// Function to read the next integer from the input stream
int getNextInt(istream& is) {
    int i;
    is >> i;
    return i;
}

int main(int argc, char* argv[]) {
    // Open the standard input if the command line argument is provided
    istream& fp = argc > 1 ? ifstream(argv[1]) : cin;

    // Initialize the scanner and writer
    istringstream scanner(fp);
    ostringstream writer;

    // Read the first two integers from the input
    int n = getNextInt(scanner);
    int m = getNextInt(scanner);

    // Initialize an unordered set to store the elements
    unordered_set<int> aa;
    // Read m elements and store them in the unordered set
    for (int i = 0; i < m; i++) {
        aa.insert(getNextInt(scanner));
    }

    // Initialize a vector of length n+1 for dynamic programming
    vector<int> dp(n+1, 0);
    // Initialize the first element of the vector
    dp[0] = 1;

    // Iterate through the array from index 0 to n-1
    for (int i = 0; i < n; i++) {
        // Iterate through the prefix sum from i to i+2
        for (int ii = 1; ii <= 2 && i+ii <= n; ii++) {
            // Skip if the current index and its sum are already present in the unordered set
            if (aa.find(i+ii) != aa.end()) {
                continue;
            }
            // Calculate the dynamic programming value for the current index
            dp[i+ii] += dp[i];
            // Perform modulo operation to keep the value within the range of 10^9+7
            dp[i+ii] %= 1000000007;
        }
    }

    // Print the final answer
    writer << dp[n] << endl;

    // Output the result
    cout << writer.str();

    return 0;
}
