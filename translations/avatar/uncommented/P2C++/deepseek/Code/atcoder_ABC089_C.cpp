#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <cmath>
#include <numeric>
#include <iomanip>
#include <functional>
#include <iterator>
#include <bitset>
#include <unordered_map>
#include <unordered_set>
#include <deque>
#include <array>
#include <random>
#include <cassert>

using namespace std;

#define int long long
#define rep(i, n) for(int i = 0; i < (n); ++i)
#define all(v) (v).begin(), (v).end()
#define rall(v) (v).rbegin(), (v).rend()
#define endl '\n'

const int INF = 1LL << 60;
const int MOD = 1000000007;

int input() {
    int n;
    cin >> n;
    return n;
}

vector<int> MAP() {
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; ++i) {
        cin >> v[i];
    }
    return v;
}

vector<string> LIST() {
    int n;
    cin >> n;
    vector<string> v(n);
    for (int i = 0; i < n; ++i) {
        cin >> v[i];
    }
    return v;
}

vector<pair<int, int>> ZIP(int n) {
    vector<pair<int, int>> v(n);
    for (int i = 0; i < n; ++i) {
        cin >> v[i].first >> v[i].second;
    }
    return v;
}

int gcd(int a, int b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}

int powmod(int a, int b, int mod) {
    int res = 1;
    while (b > 0) {
        if (b & 1) res = (res * a) % mod;
        a = (a * a) % mod;
        b >>= 1;
    }
    return res;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int N = input();
    vector<string> S = LIST();
    vector<int> march_lis(5, 0);
    vector<string> march = { "M", "A", "R", "C", "H" };

    for (const auto& s : S) {
        for (int i = 0; i < 5; ++i) {
            if (s[0] == march[i][0]) {
                ++march_lis[i];
                break;
            }
        }
    }

    int ans = 0;
    for (int i = 0; i < 5; ++i) {
        for (int j = i + 1; j < 5; ++j) {
            for (int k = j + 1; k < 5; ++k) {
                ans += march_lis[i] * march_lis[j] * march_lis[k];
            }
        }
    }

    cout << ans << endl;

    return 0;
}
