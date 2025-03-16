
#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<vector<int>> s(n, vector<int>(n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> s[i][j];
        }
    }
    set<int> rem;
    vector<int> d1, d2;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i == j) {
                d1.push_back(s[i][j]);
            }
            if (i == n - j - 1) {
                d2.push_back(s[i][j]);
            }
            if (i!= j && i!= n - j - 1) {
                rem.insert(s[i][j]);
            }
        }
    }
    if (rem.size()!= 1) {
        cout << "NO" << endl;
        return 0;
    }
    if (d1!= d2) {
        cout << "NO" << endl;
        return 0;
    }
    if (d1.size()!= 1) {
        cout << "NO" << endl;
        return 0;
    }
    if (find(rem.begin(), rem.end(), d1[0]) == rem.end()) {
        cout << "NO" << endl;
        return 0;
    }
    cout << "YES" << endl;
    return 0;
}
