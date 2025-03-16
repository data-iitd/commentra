#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <numeric>
#include <string>
#include <queue>
#include <deque>
#include <stack>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <climits>
#include <cassert>

using namespace std;

#define ll long long
#define ld long double
#define ull unsigned long long
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define ff first
#define ss second
#define fast_io ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#define set_bits(x) __builtin_popcountll(x)
#define get_bits(x) __builtin_clzll(x)
#define mod 1000000007

int main() {
    fast_io;
    int k;
    cin >> k;
    int t = 0;
    for (int i = 1; i <= k; ++i) {
        t = (t % k) * 10 + 7;
        if (t % k == 0) {
            cout << i << endl;
            return 0;
        }
    }
    cout << -1 << endl;
    return 0;
}

