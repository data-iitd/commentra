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
    for (int i = 0; i < n; i++) {
        int c = 0;
        for (int j = 0; j < n; j++) {
            if (l[i] == l[j]) {
                c++;
            }
        }
        if (c >= 2) {
            f = "No";
        }
        if (i!= 0 && l[i][0]!= l[i - 1][-1]) {
            f = "No";
        }
    }
    cout << f << endl;
    return 0;
}

