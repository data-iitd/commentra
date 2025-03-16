#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <cmath>
#include <string>
#include <cstring>

const int constMod = 1e9 + 7;

int getInt() {
    int i;
    std::cin >> i;
    return i;
}

std::vector<int> getIntSlice(int n) {
    std::vector<int> ns(n);
    for (int i = 0; i < n; i++) {
        std::cin >> ns[i];
    }
    return ns;
}

std::vector<std::vector<int>> getIntDoubleSlice(int m, int n) {
    std::vector<std::vector<int>> nds(m, std::vector<int>(n));
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            std::cin >> nds[i][j];
        }
    }
    return nds;
}

std::string getString() {
    std::string s;
    std::cin >> s;
    return s;
}

std::vector<std::string> getStringSlice(int n) {
    std::vector<std::string> ss(n);
    for (int i = 0; i < n; i++) {
        std::cin >> ss[i];
    }
    return ss;
}

std::vector<std::vector<std::string>> getStringDoubleSlice(int m, int n) {
    std::vector<std::vector<std::string>> sds(m, std::vector<std::string>(n));
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            std::cin >> sds[i][j];
        }
    }
    return sds;
}

std::vector<int> sortIntSlice(std::vector<int>& ns) {
    std::sort(ns.begin(), ns.end());
    return ns;
}

std::vector<int> sortIntReverseSlice(std::vector<int>& ns) {
    std::sort(ns.begin(), ns.end(), std::greater<int>());
    return ns;
}

int numAbs(int x) {
    return std::abs(x);
}

int numModPow(int a, int n, int m) {
    int result = 1;
    while (n > 0) {
        if (n % 2 == 1) {
            result = (result * a) % m;
        }
        a = (a * a) % m;
        n >>= 1;
    }
    return result;
}

int numGcd(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

int numLcm(int a, int b) {
    return a / numGcd(a, b) * b;
}

int numModInv(int a, int p) {
    if (a == 1) {
        return 1;
    }
    return p - numModInv(p % a, p) * (p / a) % p;
}

std::vector<int> numModFrac(int n) {
    std::vector<int> frac(n + 1, 1);
    for (int i = 1; i <= n; i++) {
        frac[i] = i * frac[i - 1] % constMod;
    }
    return frac;
}

int numModConb(int n, int r) {
    std::vector<int> frac = numModFrac(n);
    return (frac[n] * numModInv(frac[n - r], constMod) % constMod) * numModInv(frac[r], constMod) % constMod;
}

void solve() {
    int n = getInt(), m = getInt();
    std::vector<int> a = getIntSlice(n);
    int sum = std::accumulate(a.begin(), a.end(), 0);
    int count = 0;
    for (int v : a) {
        double rate = static_cast<double>(sum) / (4 * m);
        if (static_cast<double>(v) >= rate) {
            count++;
        }
    }
    std::cout << (count >= m ? "Yes" : "No") << std::endl;
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    solve();
    return 0;
}
