#include <iostream>
#include <vector>
#include <limits>

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

    int ans = numeric_limits<int>::max();
    for (int bits = 0; bits < (1 << n); bits++) {
        int tot = 0;
        bool ok = true;
        vector<int> skill(m, 0);
        for (int i = 0; i < n; i++) {
            if ((bits >> i) & 1) {
                tot += p[i];
                for (int j = 0; j < m; j++) {
                    skill[j] += a[i][j];
                }
            }
        }

        for (const auto& v : skill) {
            if (v < x) {
                ok = false;
                break;
            }
        }

        if (ok) {
            ans = min(ans, tot);
        }
    }

    if (ans != numeric_limits<int>::max()) {
        cout << ans << endl;
    } else {
        cout << "-1" << endl;
    }

    return 0;
}

// <END-OF-CODE>
