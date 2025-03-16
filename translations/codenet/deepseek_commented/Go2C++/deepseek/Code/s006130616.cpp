#include <iostream>
#include <vector>
#include <bitset>
#include <climits>

using namespace std;

int main() {
    int n, m, x;
    cin >> n >> m >> x;

    vector<vector<int>> a(n, vector<int>(m));
    vector<int> p(n);

    for (int i = 0; i < n; i++) {
        cin >> p[i];
        for (int j = 0; j < m; j++) {
            cin >> a[i][j];
        }
    }

    int ans = INT_MAX;
    for (int bits = 0; bits < (1 << n); bits++) {
        int tot = 0;
        bool ok = true;
        vector<int> skill(m, 0);

        for (int i = 0; i < n; i++) {
            if (bits & (1 << i)) {
                tot += p[i];
                for (int j = 0; j < m; j++) {
                    skill[j] += a[i][j];
                }
            }
        }

        for (int v : skill) {
            if (v < x) {
                ok = false;
                break;
            }
        }

        if (ok) {
            ans = min(ans, tot);
        }
    }

    if (ans != INT_MAX) {
        cout << ans << endl;
    } else {
        cout << "-1" << endl;
    }

