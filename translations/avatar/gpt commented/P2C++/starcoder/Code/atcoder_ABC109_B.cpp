#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<string> l(n);
    for (int i = 0; i < n; i++) {
        cin >> l[i];
    }
    string f = "Yes";
    int i = -1;
    map<string, int> s;
    for (string v : l) {
        s[v]++;
        if (s[v] >= 2) {
            f = "No";
        }
        if (i!= -1 and l[i][-1]!= v[0]) {
            f = "No";
        }
        i++;
    }
    cout << f << endl;
    return 0;
}

