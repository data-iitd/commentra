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
    }
    string f = "Yes";
    for (int i = 0; i < n - 1; i++) {
        if (s[l[i]] >= 2) {
            f = "No";
        }
        if (i!= 0 && l[i][-1]!= l[i - 1][0]) {
            f = "No";
        }
    }
    cout << f << endl;
    return 0;
}

