#include <iostream>
#include <cmath>
using namespace std;

int main() {
    int mod = 1000000007;
    int n;
    cin >> n;
    int c[n];
    for (int i = 0; i < n; i++) {
        cin >> c[i];
    }
    sort(c, c + n, greater<int>());
    int b = pow(2, 2 * n - 2, mod);
    int a = 2 * b % mod;
    int ans = 0;
    for (int i = 0; i < n; i++) {
        ans += c[i] * (a + i * b);
        ans %= mod;
    }
    cout << ans << endl;
    return 0;
}

