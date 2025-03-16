#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <string>
#include <cstring>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <sstream>

using namespace std;

const int MOD = 998244353;
const int FAC_NUM = 300001;

int Pow(int a, int n) {
    int ans = 1;
    while (n > 0) {
        if (n & 1) {
            ans = ans * a % MOD;
        }
        a = a * a % MOD;
        n >>= 1;
    }
    return ans;
}

int Gcd(int a, int b) {
    if (a < b) {
        return Gcd(b, a);
    }
    while (b != 0) {
        int temp = a % b;
        a = b;
        b = temp;
    }
    return a;
}

int min(int a, int b) {
    return a < b ? a : b;
}

int combination(int n, int k, const vector<int>& fac, const vector<int>& ifac) {
    if (n < k || n < 0) {
        return 0;
    }
    if (k == 0) {
        return 1;
    }
    int ans = ifac[k] * ifac[n - k] % MOD;
    return ans * fac[n] % MOD;
}

vector<int> factorial() {
    vector<int> fac(FAC_NUM);
    fac[0] = 1;
    for (int i = 1; i < FAC_NUM; i++) {
        fac[i] = fac[i - 1] * i % MOD;
    }
    vector<int> ifac(FAC_NUM);
    ifac[FAC_NUM - 1] = Pow(fac[FAC_NUM - 1], MOD - 2);
    for (int i = FAC_NUM - 2; i >= 0; i--) {
        ifac[i] = ifac[i + 1] * (i + 1) % MOD;
    }
    return fac;
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
    ios::sync_with_stdio(false);
    cin.tie(0);

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
