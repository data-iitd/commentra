#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

long long power(long long x, long long n) {
    if (n == 0) {
        return 1;
    }
    const int mod = 1000000007;
    long long val = power(x, n / 2);
    val = val * val % mod;
    if (n % 2 == 1) {
        val = val * x % mod;
    }
    return val;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string line;
    getline(cin, line);
    int n = stoi(line);
    
    getline(cin, line);
    vector<int> c(n);
    size_t pos = 0;
    for (int i = 0; i < n; ++i) {
        pos = line.find(' ');
        c[i] = stoi(line.substr(0, pos));
        line.erase(0, pos + 1);
    }

    const int mod = 1000000007;
    if (n == 1) {
        cout << (c[0] * 2 % mod) << endl;
        return 0;
    }

    sort(c.begin(), c.end());
    long long b = power(2, n);
    long long a = power(2, n - 2);
    long long ans = 0;

    for (int i = 2; i <= n + 1; ++i) {
        long long val = a * i % mod;
        val = val * c[n + 1 - i] % mod;
        ans = (ans + val) % mod;
    }

    ans = ans * b % mod;
    cout << ans << endl;

    return 0;
}

// <END-OF-CODE>
