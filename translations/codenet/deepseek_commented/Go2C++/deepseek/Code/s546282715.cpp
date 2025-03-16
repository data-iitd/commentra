#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <unordered_set>

using namespace std;

// getNextWord reads the next word from the input stream.
string getNextWord(istream& is) {
    string word;
    is >> word;
    return word;
}

// getNextInt reads the next word from the input stream and converts it to an integer.
int getNextInt(istream& is) {
    int i;
    is >> i;
    return i;
}

int main(int argc, char* argv[]) {
    // Determine the input source based on command-line arguments
    ifstream fp(argc > 1 ? argv[1] : "/dev/stdin");

    // Create a new input stream to read from the determined input source
    istringstream input(fp.rdbuf());

    // Create a writer to output the result
    ostringstream output;

    // Read the number of elements (n) and the number of restricted positions (m)
    int n = getNextInt(input);
    int m = getNextInt(input);

    // Create a set to store the restricted positions
    unordered_set<int> aa;
    for (int i = 0; i < m; i++) {
        aa.insert(getNextInt(input));
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
            dp[i + ii] += dp[i];
            dp[i + ii] %= 1000000007;
        }
    }

    // Print the result
    output << dp[n] << endl;

    // Output the result
    cout << output.str();

    return 0;
}
