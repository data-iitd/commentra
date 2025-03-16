#include <iostream>
#include <vector>
#include <cmath>
#include <map>
#include <algorithm>
#include <queue>
#include <iomanip>
#include <numeric>
#include <unordered_map>
#include <unordered_set>
#include <set>
#include <stack>
#include <climits>
#include <queue>
#include <deque>
#include <cstring>
#include <bitset>
#include <memory>
#include <cassert>

using namespace std;

#define int long long
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define yes cout << "Yes" << endl
#define no cout << "No" << endl
#define sz(x) (int)(x).size()
#define ioss ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define int22 vector<int>22
#define PI acos(-1)
#define int1d vector<int>
#define int2d vector<vector<int>>
#define int3d vector<vector<vector<int>>>
#define int4d vector<vector<vector<vector<int>>>>

const int INF = 999999999999999999;
const int MOD = 1000000007;

int n;

vector<int> prime_factorize(int n) {
    vector<int> a;
    while (n % 2 == 0) {
        a.pb(2);
        n /= 2;
    }
    for (int f = 3; f * f <= n; f += 2) {
        if (n % f == 0) {
            a.pb(f);
            n /= f;
        }
    }
    if (n != 1) {
        a.pb(n);
    }
    return a;
}

int factorial(int n) {
    if (n == 1) {
        return 0;
    }
    vector<int> arr;
    vector<int> factors = prime_factorize(n);
    map<int, int> fac;
    for (int num : factors) {
        fac[num]++;
    }
    int ans = 0;
    for (auto& p : fac) {
        int x = p.S;
        for (int i = 1; i <= 1000000000; ++i) {
            if (x >= i) {
                x -= i;
                ans++;
            } else {
                break;
            }
        }
    }
    return ans;
}

signed main() {
    ioss;
    cin >> n;
    if (n == 1) {
        cout << 0 << endl;
        return 0;
    }
    cout << factorial(n) << endl;
    return 0;
}
