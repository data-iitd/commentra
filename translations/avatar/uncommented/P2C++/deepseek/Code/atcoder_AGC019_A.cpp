#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <cmath>
#include <cstring>
#include <iomanip>
#include <math.h>
#include <bitset>

using namespace std;

#define int long long
#define double long double
#define pb push_back
#define mp make_pair
#define endl '\n'
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define PI 3.14159265358979323846
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define file freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout)

int gcd(int a, int b) {
    while (b) {
        a %= b;
        swap(a, b);
    }
    return a;
}

int lcm(int a, int b) {
    return a / gcd(a, b) * b;
}

int ceil(int a, int b = 1) {
    return (a + b - 1) / b;
}

int round(int x) {
    return (x * 2 + 1) / 2;
}

int fermat(int x, int y, int MOD) {
    return x * pow(y, MOD - 2, MOD) % MOD;
}

int lcm_list(vector<int>& nums) {
    int result = 1;
    for (int num : nums) {
        result = lcm(result, num);
    }
    return result;
}

int32_t main() {
    fast;
    int q, h, s, d;
    cin >> q >> h >> s >> d;
    int n;
    cin >> n;
    int best1L = min({q * 4, h * 2, s});
    int best2L = min({d, best1L * 2});
    if (n % 2 == 0) {
        cout << best2L * (n / 2) << endl;
    } else {
        cout << best2L * (n / 2) + best1L << endl;
    }
    return 0;
}
