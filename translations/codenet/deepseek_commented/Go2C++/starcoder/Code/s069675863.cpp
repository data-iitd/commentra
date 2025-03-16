
#include <bits/stdc++.h>

using namespace std;

// Constants used in the program.
const int MOD = 1000000000 + 7;
const int ALPHABET_NUM = 26;
const int INF_INT64 = numeric_limits<int64_t>::max();
const int64_t INF_BIT60 = 1 << 60;
const int INF_INT32 = numeric_limits<int32_t>::max();
const int INF_BIT30 = 1 << 30;
const int NIL = -1;
const int WHITE = 0;
const int GRAY = 1;
const int BLACK = 2;

// Global variables.
vector<int> S;
int x, y;

// Global variables for memoization.
vector<vector<bool>> dpx;
vector<vector<bool>> dpy;

// Initializes the input reader and output writer.
void init() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> S;
    cin >> x >> y;
}

// Main function reads input, processes the data, and prints the result.
int main() {
    init();

    // Preprocessing.
    int n = (int)S.size();
    dpx.resize(n + 1, vector<bool>(20001, false));
    dpy.resize(n + 1, vector<bool>(20001, false));
    dpx[0][10000] = true;
    dpy[0][10000] = true;
    for (int i = 0; i < n; i++) {
        int val = S[i];
        for (int j = 2000; j <= 18000; j++) {
            if (j + val <= 18000) {
                dpx[i + 1][j + val] = dpx[i + 1][j + val] || dpx[i][j];
            }
            if (j - val >= 2000 && i!= 0) {
                dpx[i + 1][j - val] = dpx[i + 1][j - val] || dpx[i][j];
            }
        }
    }
    for (int i = 0; i < n; i++) {
        int val = S[i];
        for (int j = 2000; j <= 18000; j++) {
            if (j + val <= 18000) {
                dpy[i + 1][j + val] = dpy[i + 1][j + val] || dpy[i][j];
            }
            if (j - val >= 2000) {
                dpy[i + 1][j - val] = dpy[i + 1][j - val] || dpy[i][j];
            }
        }
    }

    // Main algorithm.
    if (dpx[n][x + 10000] && dpy[n][y + 10000]) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }

    return 0;
}

