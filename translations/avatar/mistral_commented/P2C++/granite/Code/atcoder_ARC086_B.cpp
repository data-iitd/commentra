

#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <string>
#include <map>
#include <queue>
#include <stack>
#include <set>
#include <iomanip>
#include <numeric>
#include <tuple>
#include <bitset>
#include <complex>
#include <unistd.h>
#include <cassert>
#include <cctype>
#include <random>
#define _USE_MATH_DEFINES
#include <math.h>
#include <cstdio>
#include <ctgmath>
#include <chrono>
#include <random>
#include <functional>
#include <climits>
#include <cstdlib>
#include <cstring>
#include <sstream>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<double, double> pdd;
typedef vector<ll> vll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<vector<ll>> vvll;
typedef vector<vector<pii>> vvp;
typedef vector<vector<pll>> vvpll;
typedef vector<pair<int, pii>> vpp;
typedef vector<pair<pll, pll>> vppp;
typedef set<int> si;
typedef set<ll> sll;
typedef priority_queue<int> pqi;
typedef priority_queue<ll> pql;
typedef priority_queue<pii> pqpii;
typedef priority_queue<pll> pqpll;
const int inf = 100000000;
const ll linf = 100000000000000000;
const ld eps = 1e-9;
const int mod = 100000007;
const int dx[4] = {-1, 0, 1, 0};
const int dy[4] = {0, -1, 0, 1};
const int dx8[8] = {-1, -1, -1, 0, 0, 1, 1, 1};
const int dy8[8] = {-1, 0, 1, -1, 1, -1, 0, 1};
const double pi = acos(-1.0);

// Function to return the sign of a number
int my_sign(int x) {
    if (x > 0) return 1;
    else if (x < 0) return -1;
    else return 0;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    int N;
    cin >> N;
    vector<int> a(N);
    for (int i = 0; i < N; i++) {
        cin >> a[i];
    }
    int max_val = 0, max_sign = 0, max_index = -1;
    for (int i = 0; i < N; i++) {
        if (abs(a[i]) > max_val) {
            max_val = abs(a[i]);
            max_sign = my_sign(a[i]);
            max_index = i;
        }
    }
    if (max_sign == 0) {
        cout << 0 << endl;
    } else if (max_sign == 1) {
        cout << 2 * N - 1 << endl;
        cout << max_index + 1 << " " << 1 << endl;
        for (int i = 1; i < N; i++) {
            cout << i + 1 << " " << i + 2 << endl;
        }
    } else {
        cout << 2 * N - 1 << endl;
        cout << max_index + 1 << " " << 1 << endl;
        for (int i = N - 1; i > 0; i--) {
            cout << i + 1 << " " << i << endl;
        }
    }
    return 0;
}

