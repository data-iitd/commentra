

#include <bits/stdc++.h>

using namespace std;

// Constants used in the program.
const int MOD = 1000000000 + 7;
const int ALPHABET_NUM = 26;
const long long INF_INT64 = numeric_limits<long long>::max();
const long long INF_BIT60 = 1LL << 60;
const int INF_INT32 = numeric_limits<int>::max();
const int INF_BIT30 = 1 << 30;
const int NIL = -1;
const int WHITE = 0;
const int GRAY = 1;
const int BLACK = 2;

// init function initializes the input reader and output writer.
void init() {
    cin.tie(0);
    ios::sync_with_stdio(false);
}

// Main function reads input, processes the data, and prints the result.
int main() {
    init();

    string S;
    cin >> S;

    int x, y;
    cin >> x >> y;

    vector<int> F;
    int cur = 0;
    for (int i = 0; i < S.size(); i++) {
        if (S[i] == 'F') {
            cur++;
        } else {
            F.push_back(cur);
            cur = 0;
        }
    }
    F.push_back(cur);

    vector<vector<bool>> dpx(F.size() + 1, vector<bool>(20000, false));
    vector<vector<bool>> dpy(F.size() + 1, vector<bool>(20000, false));
    dpx[0][10000] = true;
    dpy[0][10000] = true;
    for (int i = 0; i < F.size(); i++) {
        int val = F[i];
        for (int j = 20000 - 1; j >= 0; j--) {
            if (j + val < 20000) {
                dpx[i + 1][j + val] |= dpx[i][j];
            }
            if (j - val >= 0) {
                dpx[i + 1][j - val] |= dpx[i][j];
            }
        }
    }
    for (int i = 0; i < F.size(); i++) {
        int val = F[i];
        for (int j = 20000 - 1; j >= 0; j--) {
            if (j + val < 20000) {
                dpy[i + 1][j + val] |= dpy[i][j];
            }
            if (j - val >= 0) {
                dpy[i + 1][j - val] |= dpy[i][j];
            }
        }
    }

    if (dpx[F.size()][x + 10000] && dpy[F.size()][y + 10000]) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }

    return 0;
}