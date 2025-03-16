
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include <assert.h>
#include <iostream>
#include <algorithm>
#include <iomanip>
#include <fstream>
#include <vector>
#include <bitset>
#include <queue>
#include <stack>
#include <map>
#include <set>

typedef long long ll;
using namespace std;

const int MOD = (int)1e9 + 7;
const int MAXN = 2e5 + 10;
const ll oo = 1e18 + 1;

int dx[] = { -1, 0, 1, 0 };
int dy[] = { 0, -1, 0, 1 };

int n;
ll k;
ll a[MAXN];

bool check(ll x) {
    ll tot = 0;
    for (int i = 0; i < n; i++) {
        ll now = a[i];
        int l = 0, r = n;
        if (now >= 0) {
            while (l < r) {
                int c = (l + r) / 2;
                if (now * a[c] < x) l = c + 1;
                else r = c;
            }
            tot += l;
        }
        else {
            while (l < r) {
                int c = (l + r) / 2;
                if (now * a[c] >= x) l = c + 1;
                else r = c;
            }
            tot += (n - l);
        }
        if ((ll)a[i] * a[i] < x) tot--;
    }
    if (tot / 2 < k) return true;
    else return false;
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> k;
    for (int i = 0; i < n; i++) cin >> a[i];
    sort(a, a + n);
    ll l = -oo, r = oo;
    while (l + 1 < r) {
        ll c = (l + r) / 2;
        if (check(c)) l = c;
        else r = c;
    }
    cout << l << endl;

    return 0;
}

