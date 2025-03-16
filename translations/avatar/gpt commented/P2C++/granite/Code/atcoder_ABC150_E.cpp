
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int mod = 1e9 + 7;

int main() {
    int n;
    cin >> n;
    vector<int> c(n);
    for (int i = 0; i < n; i++) {
        cin >> c[i];
    }
    sort(c.rbegin(), c.rend());
    int b = 1;
    for (int i = 0; i < 2 * n - 2; i++) {
        b = b * 2 % mod;
    }
    int a = b * 2 % mod;
    int ans = 0;
    for (int i = 0; i < n; i++) {
        ans = (ans + c[i] * (a + i * b) % mod) % mod;
    }
    cout << ans << endl;
    return 0;
}

