#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cstring>

using namespace std;

const int MOD = 1000000007;
const int MAX_COORD = 20000;
const int OFFSET = 10000;

bool dpx[8000][MAX_COORD + 1];
bool dpy[8000][MAX_COORD + 1];

int main() {
    string S;
    cin >> S;

    int x, y;
    cin >> x >> y;

    vector<int> F; // Lengths of consecutive 'F's
    int cur = 0; // Current count of consecutive 'F's

    // Count consecutive 'F's and store in F
    for (char c : S) {
        if (c == 'F') {
            cur++;
        } else {
            if (cur > 0) {
                F.push_back(cur);
                cur = 0;
            }
        }
    }
    if (cur > 0) {
        F.push_back(cur); // Append the last count of 'F's
    }

    vector<int> evens, odds; // Separate counts into even and odd indexed slices
    for (size_t i = 0; i < F.size(); i++) {
        if (i % 2 == 0) {
            evens.push_back(F[i]);
        } else {
            odds.push_back(F[i]);
        }
    }

    // Initialize the dynamic programming tables for x and y
    memset(dpx, false, sizeof(dpx));
    memset(dpy, false, sizeof(dpy));
    dpx[0][OFFSET] = true;
    dpy[0][OFFSET] = true;

    // Fill the dynamic programming table for even indexed counts
    for (size_t i = 0; i < evens.size(); i++) {
        int val = evens[i];
        for (int j = 0; j <= MAX_COORD; j++) {
            if (dpx[i][j]) {
                if (j + val <= MAX_COORD) {
                    dpx[i + 1][j + val] = true;
                }
                if (j - val >= 0) {
                    dpx[i + 1][j - val] = true;
                }
            }
        }
    }

    // Fill the dynamic programming table for odd indexed counts
    for (size_t i = 0; i < odds.size(); i++) {
        int val = odds[i];
        for (int j = 0; j <= MAX_COORD; j++) {
            if (dpy[i][j]) {
                if (j + val <= MAX_COORD) {
                    dpy[i + 1][j + val] = true;
                }
                if (j - val >= 0) {
                    dpy[i + 1][j - val] = true;
                }
            }
        }
    }

    // Check if the target coordinates can be reached
    if (dpx[evens.size()][x + OFFSET] && dpy[odds.size()][y + OFFSET]) {
        cout << "Yes" << endl; // Output "Yes" if reachable
    } else {
        cout << "No" << endl; // Output "No" if not reachable
    }

    return 0;
}

/<END-OF-CODE>
