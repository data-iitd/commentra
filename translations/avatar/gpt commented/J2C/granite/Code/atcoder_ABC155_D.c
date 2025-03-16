
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include <assert.h>

#define N 100000
#define MOD 100000007
#define EPS 1e-9
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define clr(x) memset(x, 0, sizeof(x))
#define sz(x) (int)x.size()
#define ln(x) (int)strlen(x)
#define sqr(x) (x) * (x)
#define db double
#define ll long long
#define vi vector<int>
#define vpi vector< pair<int, int> >
#define vll vector<long long>
#define vvi vector< vector<int> >
#define vvl vector< vector<long long> >
#define si set<int>
#define pii pair<int, int>
#define pll pair<long long, long long>
#define vsi vector<set<int> >
#define vpll vector< pair<long long, long long> >
#define mii map<int, int>
#define msi map<string, int>
#define mci map<char, int>
#define mll map<long long, long long>
#define endl '\n'
#define debug(x) cout << #x << " = " << x << endl;
#define debug2(x, y) cout << #x << " = " << x << ", " << #y << " = " << y << endl;
#define debug3(x, y, z) cout << #x << " = " << x << ", " << #y << " = " << y << ", " << #z << " = " << z << endl;
#define debug4(a, b, c, d) cout << #a << " = " << a << ", " << #b << " = " << b << ", " << #c << " = " << c << ", " << #d << " = " << d << endl;
#define debug5(a, b, c, d, e) cout << #a << " = " << a << ", " << #b << " = " << b << ", " << #c << " = " << c << ", " << #d << " = " << d << ", " << #e << " = " << e << endl;
#define debug6(a, b, c, d, e, f) cout << #a << " = " << a << ", " << #b << " = " << b << ", " << #c << " = " << c << ", " << #d << " = " << d << ", " << #e << " = " << e << ", " << #f << " = " << f << endl;
#define debug7(a, b, c, d, e, f, g) cout << #a << " = " << a << ", " << #b << " = " << b << ", " << #c << " = " << c << ", " << #d << " = " << d << ", " << #e << " = " << e << ", " << #f << " = " << f << ", " << #g << " = " << g << endl;
#define debug8(a, b, c, d, e, f, g, h) cout << #a << " = " << a << ", " << #b << " = " << b << ", " << #c << " = " << c << ", " << #d << " = " << d << ", " << #e << " = " << e << ", " << #f << " = " << f << ", " << #g << " = " << g << ", " << #h << " = " << h << endl;
#define debug9(a, b, c, d, e, f, g, h, i) cout << #a << " = " << a << ", " << #b << " = " << b << ", " << #c << " = " << c << ", " << #d << " = " << d << ", " << #e << " = " << e << ", " << #f << " = " << f << ", " << #g << " = " << g << ", " << #h << " = " << h << ", " << #i << " = " << i << endl;
#define debug10(a, b, c, d, e, f, g, h, i, j) cout << #a << " = " << a << ", " << #b << " = " << b << ", " << #c << " = " << c << ", " << #d << " = " << d << ", " << #e << " = " << e << ", " << #f << " = " << f << ", " << #g << " = " << g << ", " << #h << " = " << h << ", " << #i << " = " << i << ", " << #j << " = " << j << endl;

using namespace std;

const int dx[] = { -1, 0, 1, 0 };
const int dy[] = { 0, -1, 0, 1 };
const int dx8[] = { -1, -1, -1, 0, 0, 1, 1, 1 };
const int dy8[] = { -1, 0, 1, -1, 1, -1, 0, 1 };
const int kx[] = { 1, 1, 2, 2, -1, -1, -2, -2 };
const int ky[] = { 2, -2, 1, -1, 2, -2, 1, -1 };

ll powmod(ll a, ll b) {
    if (b == 0)
        return 1;
    if (b % 2 == 1)
        return a * powmod(a, b - 1) % MOD;
    ll x = powmod(a, b / 2);
    return x * x % MOD;
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    int n;
    ll k;
    cin >> n >> k;
    ll a[N];
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    sort(a, a + n);
    ll l = -1e18, r = 1e18;
    while (l + 1 < r) {
        ll c = (l + r) / 2;
        ll tot = 0;
        for (int i = 0; i < n; i++) {
            ll now = a[i];
            int l = 0, r = n;
            while (l < r) {
                int c = (l + r) / 2;
                if (now * a[c] < c)
                    l = c + 1;
                else
                    r = c;
            }
            tot += l;
            if (now * now < c)
                tot--;
        }
        if (tot / 2 < k)
            r = c;
        else
            l = c;
    }
    cout << l << endl;

    return 0;
}