#include <iostream>
#include <vector>
#include <string>
#include <cstring>

using namespace std;

const int MOD = 1000000007;
const int MAXN = 8000;
const int MAXM = 20000;

bool dpx[MAXN][MAXM];
bool dpy[MAXN][MAXM];

int main() {
    string S;
    cin >> S;

    int x, y;
    cin >> x >> y;

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

    vector<int> evens, odds;
    for (size_t i = 0; i < F.size(); i++) {
        if (i % 2 == 0) {
            evens.push_back(F[i]);
        } else {
            odds.push_back(F[i]);
        }
    }

    memset(dpx, false, sizeof(dpx));
    memset(dpy, false, sizeof(dpy));

    dpx[0][10000] = true;
    dpy[0][10000] = true;

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

    if (dpx[evens.size()][x + 10000] && dpy[odds.size()][y + 10000]) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }

    return 0;
}

/<END-OF-CODE>
