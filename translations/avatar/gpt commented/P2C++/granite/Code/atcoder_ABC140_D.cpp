
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cmath>
#include <set>
#include <map>
#include <iomanip>
#include <queue>
#include <stack>
#include <numeric>
#include <bitset>
#include <cassert>
#include <random>
#include <time.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<double, double> pdd;

const int N = 1e5 + 10;
const ll MOD = 1e9 + 7;
const ll oo = 1e18;
const ll LOG = 20;

int gi() {
    int w = 0;
    bool q = 1;
    char c = getchar();
    while ((c < '0' || c > '9') && c!= '-') c = getchar();
    if (c == '-') q = 0, c = getchar();
    while (c >= '0' && c <= '9') w = w * 10 + c - '0', c = getchar();
    return q? w : -w;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n = gi(), k = gi();
    string s;
    cin >> s;
    int cnt = 0;
    for (int i = 0; i < n - 1; i++) {
        if (s[i]!= s[i + 1]) cnt++;
    }
    int ans = n - 1 - cnt;
    if (2 * k >= cnt) ans = n - 1;
    else ans = cur_happy + 2 * k;
    cout << ans;

    return 0;
}

