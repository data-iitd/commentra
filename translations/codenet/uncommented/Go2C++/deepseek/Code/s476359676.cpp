#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    int ans = 0;
    int aPrev = 0;
    for (int i = 0; i < n; ++i) {
        if (a[i] > i || a[i] > aPrev + 1) {
            cout << "-1\n";
            return 0;
        }
        if (a[i] == aPrev + 1) {
            ans++;
        } else {
            ans += a[i];
        }
        aPrev = a[i];
    }
    cout << ans << '\n';

    return 0;
}
