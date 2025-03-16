#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

const int mod = 1000000007;

vector<int> primeFactors(int n) {
    vector<int> factors;
    for (int i = 2; i * i <= n; i++) {
        while (n % i == 0) {
            factors.push_back(i);
            n /= i;
        }
    }
    if (n > 1) {
        factors.push_back(n);
    }
    return factors;
}

int main() {
    int n;
    cin >> n;
    vector<int> as(n);
    map<int, int> ps;
    for (int i = 0; i < n; i++) {
        cin >> as[i];
        vector<int> ns = primeFactors(as[i]);
        for (int factor : ns) {
            ps[factor]++;
        }
    }

    long long x = 1;
    for (auto& p : ps) {
        int prime = p.first;
        int power = p.second;
        for (int i = 1; i <= power; i++) {
            x = (x * prime) % mod;
        }
    }

    int ans = 0;
    for (int i = 0; i < n; i++) {
        ans = (ans + modInverse(x, as[i])) % mod;
    }
    cout << ans << endl;
    return 0;
}

int pow(int n, int k) {
    if (k == 0) return 1;
    if (k % 2 == 1) return pow(n, k - 1) * n % mod;
    int t = pow(n, k / 2);
    return t * t % mod;
}

int modInverse(int a, int m) {
    return a * pow(m, mod - 2) % mod;
}

