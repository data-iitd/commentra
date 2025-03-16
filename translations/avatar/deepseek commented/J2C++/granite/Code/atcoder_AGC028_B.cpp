

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <bitset>
#include <functional>
#include <numeric>
#include <utility>
#include <iomanip>
#include <cassert>
#include <random>
#include <time.h>

using namespace std;

using lint = long long;
using ldouble = long double;

using P = pair<int, int>;
using LLP = pair<long long, long long>;

#define REP(i, n) for (int i = 0, i##_len = (n); i < i##_len; ++i)
#define REP3(i, st, n) for (int i = st; i < n; ++i)
#define REP_R(i, n) for (int i = n - 1; i >= 0; --i)
#define REP3R(i, st, n) for (int i = n - 1; i >= st; --i)
#define ALL(c) (c).begin(), (c).end()

template <typename T>
T read() {
    T t;
    cin >> t;
    return t;
}

template <typename T>
vector<T> read(int n) {
    vector<T> v;
    REP(i, n) {
        v.push_back(read<T>());
    }
    return v;
}

template <typename T>
void print(const vector<T>& v) {
    REP(i, v.size()) {
        if (i > 0) cout << " ";
        cout << v[i];
    }
    cout << endl;
}

template <typename T>
void print(const vector<vector<T>>& v) {
    REP(i, v.size()) {
        print(v[i]);
    }
}

template <typename T>
void print(const vector<vector<vector<T>>>>& v) {
    REP(i, v.size()) {
        print(v[i]);
    }
}

template <typename T>
void print(const T& t) {
    cout << t << endl;
}

template <typename T, typename U>
void print(const pair<T, U>& p) {
    cout << "(" << p.first << ", " << p.second << ")" << endl;
}

template <typename T>
inline bool chmax(T& a, T b) {
    if (a < b) {
        a = b;
        return true;
    }
    return false;
}

template <typename T>
inline bool chmin(T& a, T b) {
    if (a > b) {
        a = b;
        return true;
    }
    return false;
}

template <typename T>
T modinv(T a, T m) {
    T b = m, u = 1, v = 0;
    while (b) {
        T t = a / b;
        a -= t * b;
        swap(a, b);
        u -= t * v;
        swap(u, v);
    }
    return (u + m) % m;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout << setprecision(10) << fixed;

    int n = read<int>();
    vector<int> a = read<int>(n);

    lint mod = 1000000007;
    lint p = 1;
    REP(i, n) {
        p = p * (i + 1) % mod;
    }

    vector<lint> q(n);
    q[0] = 1;
    REP3(i, 1, n) {
        q[i] = (q[i - 1] + modinv(i + 1, mod)) % mod;
    }

    lint ans = 0;
    REP(i, n) {
        lint val = q[i] + q[n - i - 1] - 1;
        val = val * a[i] % mod;
        val = val * p % mod;
        ans = (ans + val) % mod;
    }

    print(ans);

    return 0;
}

