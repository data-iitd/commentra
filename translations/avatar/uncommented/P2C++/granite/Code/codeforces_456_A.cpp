
#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<vector<int>> m(n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> m[i][j];
        }
    }
    sort(m.begin(), m.end(), [](const vector<int>& a, const vector<int>& b) {
        return a[1] > b[1];
    });
    bool flag = false;
    for (int i = 1; i < n; i++) {
        if (m[i][1] > m[i - 1][1]) {
            cout << "Happy Alex" << endl;
            flag = true;
            break;
        }
    }
    if (!flag) {
        cout << "Poor Alex" << endl;
    }
    return 0;
}
