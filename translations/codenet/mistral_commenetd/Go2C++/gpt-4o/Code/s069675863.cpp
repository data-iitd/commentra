#include <iostream>
#include <vector>
#include <string>
#include <cstring>

using namespace std;

const int MOD = 1000000007;
const int MAX_ROWS = 8000;
const int MAX_COLS = 20000;

bool dpx[MAX_ROWS][MAX_COLS];
bool dpy[MAX_ROWS][MAX_COLS];

void updateDPX(int index, int val, int maxIndex) {
    for (int j = 2000; j <= 18000; j++) {
        if (j + val <= 18000) {
            dpx[index + 1][j + val] = dpx[index + 1][j + val] || dpx[index][j];
        }
        if (j - val >= 2000 && index != 0) {
            dpx[index + 1][j - val] = dpx[index + 1][j - val] || dpx[index][j];
        }
    }
}

void updateDPY(int index, int val) {
    for (int j = 2000; j <= 18000; j++) {
        if (j + val <= 18000) {
            dpy[index + 1][j + val] = dpy[index + 1][j + val] || dpy[index][j];
        }
        if (j - val >= 2000) {
            dpy[index + 1][j - val] = dpy[index + 1][j - val] || dpy[index][j];
        }
    }
}

int main() {
    string S;
    cin >> S;

    int x, y;
    cin >> x >> y;

    memset(dpx, false, sizeof(dpx));
    memset(dpy, false, sizeof(dpy));

    dpx[0][10000] = true; // Starting point for dpx
    dpy[0][10000] = true; // Starting point for dpy

    vector<int> evens, odds;

    for (char c : S) {
        int val = c - '0';
        if (val % 2 == 0) {
            evens.push_back(val);
        } else {
            odds.push_back(val);
        }
    }

    for (int i = 0; i < evens.size(); i++) {
        updateDPX(i, evens[i], evens.size());
    }

    for (int i = 0; i < odds.size(); i++) {
        updateDPY(i, odds[i]);
    }

    if (dpx[evens.size()][x + 10000] && dpy[odds.size()][y + 10000]) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }

    return 0;
}

// <END-OF-CODE>
