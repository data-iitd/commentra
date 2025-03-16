

#include <bits/stdc++.h>

using namespace std;

int main() {
    // Read a string from the standard input
    string S;
    cin >> S;

    // Parse two integers from the string and assign them to the variables x and y
    int x, y;
    cin >> x >> y;

    // Initialize a 2D boolean array dpx and dpy with the size of 8000 x 20000
    vector<vector<bool>> dpx(8000, vector<bool>(20000, false));
    vector<vector<bool>> dpy(8000, vector<bool>(20000, false));

    // Iterate through the even indices of the F slice and update the dpx array accordingly
    for (int i = 0; i < S.size(); i += 2) {
        int val = S[i] - '0';
        for (int j = 2000; j <= 18000; j++) {
            if (j + val <= 18000) {
                dpx[i / 2 + 1][j + val] |= dpx[i / 2][j];
            }
            if (j - val >= 2000 && i!= 0) {
                dpx[i / 2 + 1][j - val] |= dpx[i / 2][j];
            }
        }
    }

    // Iterate through the odd indices of the F slice and update the dpy array accordingly
    for (int i = 1; i < S.size(); i += 2) {
        int val = S[i] - '0';
        for (int j = 2000; j <= 18000; j++) {
            if (j + val <= 18000) {
                dpy[i / 2 + 1][j + val] |= dpy[i / 2][j];
            }
            if (j - val >= 2000) {
                dpy[i / 2 + 1][j - val] |= dpy[i / 2][j];
            }
        }
    }

    // Check if the boolean values at the indices (len(evens) + 1) and (len(odds) + 1) corresponding to x and y are both true
    if (dpx[S.size() / 2][x + 10000] && dpy[S.size() / 2][y + 10000]) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }

    return 0;
}
