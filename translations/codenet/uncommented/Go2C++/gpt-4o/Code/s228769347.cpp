#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(int argc, char *argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // Input handling
    if (argc > 1) {
        freopen(argv[1], "r", stdin);
        if (argc > 2) {
            freopen(argv[2], "w", stdout);
        }
    }

    int n;
    cin >> n;
    vector<int> ll(n);

    for (int i = 0; i < n; i++) {
        cin >> ll[i];
    }

    sort(ll.begin(), ll.end());

    long long ans = 0;
    for (int i = 0; i < n - 2; i++) {
        for (int j = i + 1; j < n - 1; j++) {
            int l = j + 1;
            int r = n;
            while (l < r) {
                int m = (l + r) / 2;
                if (ll[m] < ll[i] + ll[j]) {
                    l = m + 1;
                } else {
                    r = m;
                }
            }
            ans += l - (j + 1);
        }
    }

    cout << ans << '\n';

    return 0;
}
// <END-OF-CODE>
