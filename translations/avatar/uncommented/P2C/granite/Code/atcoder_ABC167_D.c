
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include <assert.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <set>
#include <map>
#define endl '\n'
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define MOD 100000007
#define PI 3.1415926535897932384626433832795
#define deb(x) cout << #x << " = " << x << endl
#define deb2(x, y) cout << #x << " = " << x << ", " << #y << " = " << y << endl
#define all(x) x.begin(), x.end()
#define clr(x) memset(x, 0, sizeof(x))
#define sortall(x) sort(all(x))
#define tr(it, a) for (auto it = a.begin(); it!= a.end(); it++)
#define PI 3.1415926535897932384626433832795
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<pii> vpii;
typedef vector<pll> vpll;
typedef vector<vi> vvi;
typedef vector<vl> vvl;

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, k;
    cin >> n >> k;
    vector<int> l(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> l[i];
    }
    vector<int> path;
    int ind = 0, count = 0, x = 1, t = -1;
    bool flag = false;
    map<int, int> Hash;
    for (int i = 0; i <= n; i++) {
        int ne = l[x];
        if (Hash[ne]) {
            flag = true;
            t = Hash[ne];
            break;
        }
        path.pb(ne);
        ind++;
        Hash[ne] = ind;
        x = ne;
    }
    if (flag) {
        vector<int> loop = vector<int>(path.begin() + t, path.end());
        if (k < (int)path.size()) {
            cout << path[k - 1] << endl;
        } else {
            k -= (int)path.size();
            k %= (int)loop.size();
            cout << loop[k - 1] << endl;
        }
    } else {
        cout << path[k - 1] << endl;
    }

    return 0;
}
