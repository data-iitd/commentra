#include <iostream>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

// Function to read the next word from the input stream.
string getNextWord(istream& is) {
    string word;
    is >> word;
    return word;
}

// Function to convert the next word from the input stream to an integer.
int getNextInt(istream& is) {
    string word = getNextWord(is);
    return stoi(word);
}

// Main function to compute the minimum number of matrix multiplications.
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // Initialize input and output streams.
    istream& input = cin;
    ostream& output = cout;

    // Read the number of matrices.
    int n = getNextInt(input);

    // Initialize vectors for matrix dimensions and dynamic programming.
    vector<int> mm(n + 1);
    vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));

    // Read matrix dimensions into the mm vector.
    for (int i = 0; i < n; ++i) {
        mm[i] = getNextInt(input);
        mm[i + 1] = getNextInt(input);
    }

    // Use dynamic programming to compute the minimum number of multiplications.
    for (int l = 2; l <= n; ++l) {
        for (int i = 1; i <= n - l + 1; ++i) {
            int j = i + l - 1;
            for (int k = i; k <= j - 1; ++k) {
                int d = dp[i][k] + dp[k + 1][j] + mm[i - 1] * mm[k] * mm[j];
                if (dp[i][j] == 0 || dp[i][j] > d) {
                    dp[i][j] = d;
                }
            }
        }
    }

    // Print the result to the standard output.
    output << dp[1][n] << '\n';

    return 0;
}
