
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
    for (int i = 0; i < n; i++) {
        if (s[l[i]] > 1) {
            f = "No";
            break;
        }
        if (i > 0 && l[i - 1][l[i - 1].size() - 1]!= l[i][0]) {
            f = "No";
            break;
        }
    }
    cout << f << endl;
}
