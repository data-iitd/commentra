#include <iostream>
#include <vector>
#include <unordered_set>
#include <string>
#include <sstream>

using namespace std;

// Helper function to read the next word from the input stream.
string getNextWord(istream& is) {
    string word;
    is >> word;
    return word;
}

// Helper function to read the next integer from the input stream.
int getNextInt(istream& is) {
    int i;
    is >> i;
    return i;
}

int main() {
    // Set the input source to standard input; if a file is provided as an argument, open that file.
    istream* fp = &cin;
    if (argc > 1) {
        fp = new ifstream(argv[1]);
    }

    // Create a new input stream to read from the input source and configure it to split input into words.
    istringstream iss(*fp);

    // Create a buffered writer to output results to standard output.
    ostringstream oss;

    // Read the first two integers, n and m, from the input.
    int n = getNextInt(iss);
    int m = getNextInt(iss);

    // Initialize a set to store the positions that are blocked (not allowed).
    unordered_set<int> aa;
    for (int i = 0; i < m; i++) {
        // Read each blocked position and mark it in the set.
        aa.insert(getNextInt(iss));
    }

    // Create a dynamic programming array to store the number of ways to reach each position.
    vector<int> dp(n + 1, 0);
    dp[0] = 1; // Base case: There is one way to be at the starting position (doing nothing).

    // Iterate through each position from 0 to n.
    for (int i = 0; i < n; i++) {
        // Check the next two positions (i+1 and i+2) to see if they can be reached.
        for (int ii = 1; ii <= 2 && i + ii <= n; ii++) {
            if (aa.find(i + ii) != aa.end()) { // Check if the next position is blocked.
                continue; // If blocked, skip to the next iteration.
            }
            // Update the number of ways to reach position i+ii based on the current position i.
            dp[i + ii] = (dp[i + ii] + dp[i]) % 1000000007;
        }
    }

    // Output the total number of ways to reach position n.
    oss << dp[n] << endl;

    // Flush the buffered writer to ensure all output is written.
    cout << oss.str();

    // Clean up the input stream if a file was opened.
    if (fp != &cin) {
        delete fp;
    }

    return 0;
}
