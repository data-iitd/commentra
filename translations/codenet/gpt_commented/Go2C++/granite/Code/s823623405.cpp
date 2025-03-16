
#include <iostream>
#include <vector>
#include <map>

using namespace std;

const int mod = 1000000007;

int max(int a, int b) {
    return a > b? a : b;
}

map<int, int> primeFactorize(int n) {
    map<int, int> res;
    for (int i = 2; i * i <= n; i++) {
        while (n % i == 0) {
            n /= i;
            res[i]++;
        }
    }
    if (n!= 1) {
        res[n]++;
    }
    return res;
}

int pow(int n, int k) {
    if (k == 0) {
        return 1;
    } else if (k % 2 == 1) {
        return pow(n, k - 1) * n % mod;
    } else {
        int t = pow(n, k / 2);
        return t * t % mod;
    }
}

int add(int a, int b) {
    return (a + b) % mod;
}

int sub(int a, int b) {
    return (a + mod - b) % mod;
}

int mul(int a, int b) {
    return a % mod * b % mod % mod;
}

int div(int a, int b) {
    return mul(a, pow(b, mod - 2));
}

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    map<int, int> ps;
    for (int i = 0; i < n; i++) {
        auto ns = primeFactorize(a[i]);
        for (auto [k, v] : ns) {
            ps[k] = max(ps[k], v);
        }
    }
    int x = 1;
    for (auto [k, v] : ps) {
        for (int i = 1; i <= v; i++) {
            x = mul(x, k);
        }
    }
    int ans = 0;
    for (int i = 0; i < n; i++) {
        ans = add(ans, div(x, a[i]));
    }
    cout << ans << endl;
    return 0;
}

// END-OF-CODE