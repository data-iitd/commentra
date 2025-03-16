

```cpp
#include <bits/stdc++.h>
using namespace std;

int main() {
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

    vector<vector<bool>> dpx(F.size() + 1, vector<bool>(40001, false));
    vector<vector<bool>> dpy(F.size() + 1, vector<bool>(40001, false));
    dpx[0][20000] = true;
    dpy[0][20000] = true;

    for (int i = 0; i < F.size(); i++) {
        for (int j = 0; j <= 40000; j++) {
            if (j + F[i] <= 40000) {
                dpx[i + 1][j + F[i]] |= dpx[i][j];
            }
            if (j - F[i] >= 0) {
                dpx[i + 1][j - F[i]] |= dpx[i][j];
            }
            if (j + F[i] <= 40000) {
                dpy[i + 1][j + F[i]] |= dpy[i][j];
            }
            if (j - F[i] >= 0) {
                dpy[i + 1][j - F[i]] |= dpy[i][j];
            }
        }
    }

    if (dpx[F.size()][x + 20000] && dpy[F.size()][y + 20000]) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }

    return 0;
}

