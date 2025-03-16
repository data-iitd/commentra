#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, m, x, min = INT_MAX;
    cin >> n >> m >> x;
    vector<vector<int>> a(n, vector<int>(m + 1));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= m; j++) {
            cin >> a[i][j];
        }
    }
    for (int i = 0; i < (1 << n); i++) {
        vector<int> status(n);
        for (int j = 0; j < n; j++) {
            if ((1 & i >> j) == 1) {
                status[j] = 1;
            }
        }
        vector<int> res(m + 1);
        for (int j = 0; j < n; j++) {
            if (status[j] == 1) {
                for (int k = 0; k <= m; k++) {
                    res[k] += a[j][k];
                }
            }
        }
        bool flag = true;
        for (int j = 1; j <= m; j++) {
            if (res[j] < x) {
                flag = false;
                break;
            }
        }
        if (flag) {
            min = min < res[0]? min : res[0];
        }
    }
    if (min == INT_MAX) {
        cout << -1 << endl;
    } else {
        cout << min << endl;
    }
    return 0;
}

