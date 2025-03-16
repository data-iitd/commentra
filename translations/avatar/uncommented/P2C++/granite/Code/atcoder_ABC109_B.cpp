
#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    map<string, int> s;
    vector<string> l(n);
    for (int i = 0; i < n; i++) {
        cin >> l[i];
        s[l[i]]++;
        if (s[l[i]] >= 2) {
            cout << "No" << endl;
            return 0;
        }
    }
    for (int i = 1; i < n; i++) {
        if (l[i - 1][l[i - 1].size() - 1]!= l[i][0]) {
            cout << "No" << endl;
            return 0;
        }
    }
    cout << "Yes" << endl;
    return 0;
}

