#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <sstream>
#include <cmath>

const int mod = 998244353;
const int facNum = 300001;

int Pow(int a, int n) {
    int ans = 1;
    while (n > 0) {
        if (n & 1) {
            ans = ans * a % mod;
        }
        a = a * a % mod;
        n = n >> 1;
    }
    return ans;
}

int Gcd(int a, int b) {
    if (a < b) {
        return Gcd(b, a);
    }
    while (b != 0) {
        a = a % b;
        std::swap(a, b);
    }
    return a;
}

int min(int a, int b) {
    if (a < b) {
        return a;
    }
    return b;
}

int combination(int n, int k, const std::vector<int>& fac, const std::vector<int>& ifac) {
    if (n < k || n < 0) {
        return 0;
    }
    if (k == 0) {
        return 1;
    }
    int ans = ifac[k] * ifac[n - k] % mod;
    return ans * fac[n] % mod;
}

std::vector<int> factorial() {
    std::vector<int> fac(facNum);
    fac[0] = 1;
    for (int i = 1; i < facNum; i++) {
        fac[i] = fac[i - 1] * i % mod;
    }
    std::vector<int> ifac(facNum);
    ifac[facNum - 1] = Pow(fac[facNum - 1], mod - 2);
    for (int i = facNum - 2; i >= 0; i--) {
        ifac[i] = ifac[i + 1] * (i + 1) % mod;
    }
    return ifac;
}

int lowerBound(const std::vector<int>& vs, int v) {
    int n = vs.size() / 2;
    int m = vs.size();
    while (m != n) {
        if (vs[n] < v) {
            n = (m - n + 1) / 2 + n;
        } else {
            m = n;
            n = n / 2;
        }
    }
    return n;
}

std::vector<int> IntSlice(int n, int init) {
    std::vector<int> r(n, init);
    return r;
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int N;
    std::cin >> N;
    int sum = 0;
    for (int i = 1; i <= N; i++) {
        if (i % 3 == 0 || i % 5 == 0) {
            continue;
        }
        sum += i;
    }
    std::cout << sum << '\n';

    return 0;
}
