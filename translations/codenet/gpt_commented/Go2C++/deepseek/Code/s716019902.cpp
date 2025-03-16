#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <sstream>
#include <cmath>

using namespace std;

const int mod = 998244353;
const int facNum = 300001;

int Pow(int a, int n) {
    int ans = 1;
    while (n > 0) {
        if (n & 1) {
            ans = ans * a % mod;
        }
        a = a * a % mod;
        n >>= 1;
    }
    return ans;
}

int Gcd(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

int min(int a, int b) {
    return a < b ? a : b;
}

int combination(int n, int k, const vector<int>& fac, const vector<int>& ifac) {
    if (n < k || n < 0) return 0;
    if (k == 0) return 1;
    int ans = ifac[k] * ifac[n - k] % mod;
    return ans * fac[n] % mod;
}

vector<int> factorial() {
    vector<int> fac(facNum);
    fac[0] = 1;
    for (int i = 1; i < facNum; i++) {
        fac[i] = fac[i - 1] * i % mod;
    }
    vector<int> ifac(facNum);
    ifac[facNum - 1] = Pow(fac[facNum - 1], mod - 2);
    for (int i = facNum - 2; i >= 0; i--) {
        ifac[i] = ifac[i + 1] * (i + 1) % mod;
    }
    return ifac;
}

int lowerBound(const vector<int>& vs, int v) {
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

vector<int> IntSlice(int n, int init) {
    vector<int> r(n, init);
    return r;
}

int main() {
    int N;
    cin >> N;
    int sum = 0;

    for (int i = 1; i <= N; i++) {
        if (i % 3 == 0 || i % 5 == 0) {
            continue;
        }
        sum += i;
    }

    cout << sum << endl;
    return 0;
}
