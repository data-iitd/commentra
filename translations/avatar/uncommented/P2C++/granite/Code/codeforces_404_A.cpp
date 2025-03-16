
#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<string> s(n);
    for (int i = 0; i < n; i++) {
        cin >> s[i];
    }
    bool flag = false;
    vector<char> d1, d2;
    set<char> rem;
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
    } else if (d1!= d2) {
        cout << "NO" << endl;
    } else if (set<char>(d1.begin(), d1.end())!= rem) {
        cout << "NO" << endl;
    } else {
        cout << "YES" << endl;
    }
    return 0;
}
