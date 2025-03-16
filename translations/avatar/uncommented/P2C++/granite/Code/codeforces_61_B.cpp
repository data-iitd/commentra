
#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
#define int long long
#define double long double
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define gcd __gcd
#define lcm(a, b) (a * b) / gcd(a, b)
#define rep(i, a, b) for (int i = a; i < b; i++)
#define trav(a, x) for (auto &a : x)
#define sz(a) (int)a.size()
#define fill(a, b) memset(a, b, sizeof(a))
#define sortall(a) sort(all(a))
#define endl "\n"
#define trace(x) cout << #x << ": " << x << endl;
#define trace2(x, y) cout << #x << ": " << x << " | " << #y << ": " << y << endl;
#define trace3(x, y, z) cout << #x << ": " << x << " | " << #y << ": " << y << " | " << #z << ": " << z << endl;

typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<pii> vpii;
typedef vector<vi> vvi;
typedef vector<vvi> vvvi;
const int MOD = 1e9 + 7;
const int MOD1 = 998244353;
const int MAX = 2e5 + 5;
const double eps = 1e-10;
const double PI = acos(-1.0);

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    vector<string> v(3);
    rep(i, 0, 3) {
        string s;
        cin >> s;
        string t = "";
        for (char c : s) {
            if (c == '-' || c == ';' || c == '_') continue;
            t += tolower(c);
        }
        v[i] = t;
    }

    sort(all(v));
    do {
        string s = "";
        for (string t : v) s += t;
        if (s == "ahocorasick") {
            cout << "ACC" << endl;
            return 0;
        }
    } while (next_permutation(all(v)));

    cout << "WA" << endl;

    return 0;
}

