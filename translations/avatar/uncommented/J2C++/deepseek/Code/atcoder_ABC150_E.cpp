#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

long long power(long long x, long long n) {
    if (n == 0) {
        return 1;
    }
    long long mod = 1000000007;
    long long val = power(x, n / 2);
    val = val * val % mod;
    if (n % 2 == 1) {
        val = val * x % mod;
    }
    return val;
}

int main() {
    int n;
    cin >> n;
    vector<int> c(n);
    for (int i = 0; i < n; i++) {
        cin >> c[i];
    }
    sort(c.begin(), c.end());
    long long b = power(2, n);
    long long a = power(2, n - 2);
    long long ans = 0;
    for (int i = 2; i <= n + 1; i++) {
        long long val = a * i % 1000000007;
        val *= c[n + 1 - i];
        val %= 1000000007;
        ans += val;
        ans %= 1000000007;
    }
    ans *= b;
    ans %= 1000000007;
    cout << ans << endl;
    return 0;
}

