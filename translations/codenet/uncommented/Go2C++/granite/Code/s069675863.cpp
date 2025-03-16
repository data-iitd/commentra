

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

    vector<bool> dpx(20001, false);
    vector<bool> dpy(20001, false);
    dpx[10000] = true;
    dpy[10000] = true;
    for (int i = 0; i < F.size(); i++) {
        for (int j = 20000; j >= 0; j--) {
            if (j + F[i] <= 20000) {
                dpx[j + F[i]] |= dpx[j];
            }
            if (j - F[i] >= 0) {
                dpy[j - F[i]] |= dpy[j];
            }
        }
    }

    if (dpx[x + 10000] && dpy[y + 10000]) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }

    return 0;
}

