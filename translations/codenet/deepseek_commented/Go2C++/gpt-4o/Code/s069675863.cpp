// Including necessary libraries for the program.
#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>
#include <cmath>
#include <iomanip>

using namespace std;

// Constants used in the program.
const int MOD = 1000000000 + 7;
const int ALPHABET_NUM = 26;
const long long INF_INT64 = LLONG_MAX;
const long long INF_BIT60 = 1LL << 60;
const int INF_INT32 = INT_MAX;
const int INF_BIT30 = 1 << 30;
const int NIL = -1;
const int WHITE = 0;
const int GRAY = 1;
const int BLACK = 2;

// Function to read a line of input.
string ReadString() {
    string input;
    getline(cin, input);
    return input;
}

// Function to read two integers.
pair<int, int> ReadInt2() {
    int x, y;
    cin >> x >> y;
    return {x, y};
}

// Main function reads input, processes the data, and prints the result.
int main() {
    string S = ReadString();
    auto [x, y] = ReadInt2();

    vector<int> F;
    int cur = 0;
    for (char c : S) {
        if (c == 'F') {
            cur++;
        } else {
            F.push_back(cur);
            cur = 0;
        }
    }
    F.push_back(cur);

    // Debug output
    cerr << "F: ";
    for (int f : F) cerr << f << " ";
    cerr << endl;

    vector<int> evens, odds;
    for (size_t i = 0; i < F.size(); i++) {
        if (i % 2 == 0) {
            evens.push_back(F[i]);
        } else {
            odds.push_back(F[i]);
        }
    }

    const int OFFSET = 10000;
    const int MAX_SIZE = 20000;
    vector<vector<bool>> dpx(evens.size() + 1, vector<bool>(MAX_SIZE, false));
    vector<vector<bool>> dpy(odds.size() + 1, vector<bool>(MAX_SIZE, false));

    dpx[0][OFFSET] = true;
    dpy[0][OFFSET] = true;

    for (size_t i = 0; i < evens.size(); i++) {
        int val = evens[i];
        for (int j = 2000; j <= 18000; j++) {
            if (j + val <= 18000) {
                dpx[i + 1][j + val] = dpx[i + 1][j + val] || dpx[i][j];
            }
            if (j - val >= 2000 && i != 0) {
                dpx[i + 1][j - val] = dpx[i + 1][j - val] || dpx[i][j];
            }
        }
    }

    for (size_t i = 0; i < odds.size(); i++) {
        int val = odds[i];
        for (int j = 2000; j <= 18000; j++) {
            if (j + val <= 18000) {
                dpy[i + 1][j + val] = dpy[i + 1][j + val] || dpy[i][j];
            }
            if (j - val >= 2000) {
                dpy[i + 1][j - val] = dpy[i + 1][j - val] || dpy[i][j];
            }
        }
    }

    if (dpx[evens.size()][x + OFFSET] && dpy[odds.size()][y + OFFSET]) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }

    return 0;
}

// <END-OF-CODE>
