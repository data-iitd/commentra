#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> c(n);
    for (int i = 0; i < n; i++) {
        cin >> c[i];
    }

    int mod = 1000000007;
    if (n == 1) {
        cout << c[0] * 2 % mod << endl;
        return 0;
    }
    sort(c.begin(), c.end());

    long b = power(2, n);
    long a = power(2, n - 2);
    long ans = 0;

    for (int i = 2; i <= n + 1; i++) {
        long val = a * i % mod;
        val *= c[n + 1 - i];
        val %= mod;
        ans += val;
        ans %= mod;
    }
    ans *= b;
    ans %= mod;
    cout << ans << endl;

    return 0;
}

long power(long x, long n) {
    if (n == 0) {
        return 1;
    }
    int mod = 1000000007;
    long val = power(x, n / 2);
    val = val * val % mod;
    if (n % 2 == 1) {
        val = val * x % mod;
    }
    return val;
}

