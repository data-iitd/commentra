
#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector<string> l(n);
    for (int i = 0; i < n; i++) {
        cin >> l[i];
        for (int j = 0; j < m; j++) {
            if (l[i][j] == '.') {
                if ((i + j) % 2 == 0) {
                    l[i][j] = 'B';
                } else {
                    l[i][j] = 'W';
                }
            }
        }
    }
    for (int i = 0; i < n; i++) {
        cout << l[i] << endl;
    }
    return 0;
}

