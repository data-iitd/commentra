#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

long long power(long long x, long long n, int mod) {
    if (n == 0) {
        return 1; // Base case: x^0 is 1
    }
    long long val = power(x, n / 2, mod); // Recursive call to calculate x^(n/2)
    val = val * val % mod; // Squaring the result
    if (n % 2 == 1) {
        val = val * x % mod; // Multiplying by x if n is odd
    }
    return val; // Returning the result
}

int main() {
    int n;
    cin >> n;
    vector<int> c(n);
    for (int i = 0; i < n; i++) {
        cin >> c[i];
    }

    const int mod = 1000000007;
    if (n == 1) {
        cout << c[0] * 2 % mod << endl;
        return 0;
    }

    sort(c.begin(), c.end());

    long long b = power(2, n, mod);
    long long a = power(2, n - 2, mod);
    long long ans = 0;

    for (int i = 2; i <= n + 1; i++) {
        long long val = a * i % mod;
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
