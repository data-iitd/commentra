#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

const int mod = 1000000007;

int main() {
    int n;
    cin >> n;

    vector<int> c(n);
    for (int i = 0; i < n; ++i) {
        cin >> c[i];
    }

    sort(c.begin(), c.end(), greater<int>());

    long long b = pow(2, 2 * n - 2) % mod;
    long long a = 2 * b % mod;

    long long ans = 0;

    for (int i = 0; i < n; ++i) {
        ans += static_cast<long long>(c[i]) * (a + i * b);
        ans %= mod;
    }

    cout << ans << endl;

    return 0;
}

