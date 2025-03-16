#include <iostream>
#include <vector>
#include <string>
#include <sstream>

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
        int a = a[i];
        if (a > i || a > aPrev + 1) {
            cout << "-1\n";
            return 0;
        }
        if (a == aPrev + 1) {
            ++ans;
        } else {
            ans += a;
        }
        aPrev = a;
    }
    cout << ans << '\n';

    return 0;
}
