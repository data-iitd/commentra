// Include necessary headers
#include <iostream>
#include <vector>
#include <string>
#include <bitset>
#include <algorithm>

using namespace std;

// Constants for large prime numbers used in modular arithmetic.
const int INF = 1000000007;
const int INF2 = 1000000009;
const int INF3 = 998244353;

// Constants for black cell representation.
const int Black = 35;

// Function to count the number of black cells in a grid.
int countBlack(int h, int w, const vector<vector<int>>& m) {
    int count = 0;
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            if (m[i][j] == Black) {
                count++;
            }
        }
    }
    return count;
}

// Function to solve the problem.
int solve(int h, int w, int a, const vector<vector<int>>& m) {
    int result = 0;
    for (int i = 0; i < (1 << h); i++) {
        for (int k = 0; k < (1 << w); k++) {
            vector<vector<int>> tmp = m; // Copy the original matrix
            for (int j = 0; j < h; j++) {
                if (i & (1 << j)) { // Check if row j is painted
                    for (int l = 0; l < w; l++) {
                        tmp[j][l] = 1; // Paint the row
                    }
                }
            }
            for (int j = 0; j < w; j++) {
                if (k & (1 << j)) { // Check if column j is painted
                    for (int l = 0; l < h; l++) {
                        tmp[l][j] = 1; // Paint the column
                    }
                }
            }
            if (countBlack(h, w, tmp) == a) {
                result++;
            }
        }
    }
    return result;
}

// Main function for solving the problem.
int main() {
    // Read input
    int h, w, a;
    cin >> h >> w >> a;
    vector<vector<int>> m(h, vector<int>(w));
    for (int i = 0; i < h; i++) {
        string s;
        cin >> s;
        for (int j = 0; j < w; j++) {
            m[i][j] = static_cast<int>(s[j]); // Convert character to int
        }
    }

    // Solve the problem
    int answer = solve(h, w, a, m);

    // Print the result
    cout << answer << endl;

    return 0;
}

// <END-OF-CODE>
