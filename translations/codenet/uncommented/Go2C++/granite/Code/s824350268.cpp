
```cpp
#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <bitset>
#include <numeric>
#include <cstdio>
#include <cstdlib>
#include <cctype>
#include <cstring>
#include <climits>
#include <cassert>
#include <ccomplex>
#include <sstream>
#include <iomanip>
#include <valarray>
#include <array>
#include <list>
#include <forward_list>
#include <unordered_map>
#include <unordered_set>
#include <functional>
#include <random>
#include <regex>

using namespace std;

#define int long long
#define double long double
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define endl '\n'

const int MOD = 1e9 + 7;
const int MAXN = 1e6 + 10;
const int MAXA = 1e7 + 10;
const int MAXK = 1e6 + 10;
const int MAXQ = 1e5 + 10;
const int MAXLOG = 21;
const double PI = 3.14159265358979323846;
const double EPS = 1e-9;

template<typename T>
T gcd(T a, T b) {
    return (b == 0)? a : gcd(b, a % b);
}

template<typename T>
T lcm(T a, T b) {
    return a / gcd(a, b) * b;
}

template<typename T>
T mod_add(T a, T b, T mod) {
    a = a % mod;
    b = b % mod;
    return (((a + b) % mod) + mod) % mod;
}

template<typename T>
T mod_mul(T a, T b, T mod) {
    a = a % mod;
    b = b % mod;
    return (((a * b) % mod) + mod) % mod;
}

template<typename T>
T mod_pow(T b, T p, T mod) {
    T res = 1;
    while (p > 0) {
        if (p & 1) {
            res = mod_mul(res, b, mod);
        }
        b = mod_mul(b, b, mod);
        p >>= 1;
    }
    return res;
}

template<typename T>
T mod_inv(T a, T mod) {
    return mod_pow(a, mod - 2, mod);
}

template<typename T>
void print_vector(const vector<T>& vec) {
    for (const auto& x : vec) {
        cout << x << " ";
    }
    cout << endl;
}

template<typename T>
void print_array(const T arr[], int n) {
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int getInt() {
    int x;
    cin >> x;
    return x;
}

string getString() {
    string s;
    cin >> s;
    return s;
}

double getDouble() {
    double x;
    cin >> x;
    return x;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n = getInt();
    int sqrt_n = sqrt(n);
    int ans = n;
    for (int i = 1; i <= sqrt_n; i++) {
        if (n % i == 0) {
            int num = i + (n / i) - 2;
            ans = min(ans, num);
        }
    }
    cout << ans << endl;

    return 0;
}

