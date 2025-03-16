#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

const int mod = 1000000007;

vector<int> primeFactorize(int n) {
    vector<int> res;
    for (int i = 2; i * i <= n; i++) {
        while (n % i == 0) {
            res.push_back(i);
            n /= i;
        }
    }
    if (n != 1) {
        res.push_back(n);
    }
    return res;
}

int max(int a, int b) {
    return a > b ? a : b;
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
    vector<int> as(n);
    map<int, int> ps;
    for (int i = 0; i < n; i++) {
        cin >> as[i];

        vector<int> ns = primeFactorize(as[i]);
        for (int k : ns) {
            ps[k] = max(ps[k], 1);
        }
    }

    int x = 1;
    for (auto& p : ps) {
        for (int i = 1; i <= p.second; i++) {
            x = mul(x, p.first);
        }
    }

    int ans = 0;
    for (int i = 0; i < n; i++) {
        ans = add(ans, div(x, as[i]));
    }
    cout << ans << endl;
}

