
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double
#define endl "\n"
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define clr(x) memset(x, 0, sizeof(x))
#define sortall(x) sort(all(x)))
#define tr(it, x) for (auto it = x.begin(); it!= x.end(); it++)
#define PI 3.1415926535897932384626433832795

typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<pii> vpii;
typedef vector<pll> vpll;

const int MOD = 100000007;
const int dx[] = {1, -1, 0, 0};
const int dy[] = {0, 0, 1, -1};

// Function to solve the problem
void solve() {
    ll n, a, b;
    cin >> n >> a >> b;

    if (n < a) {
        cout << "No" << endl;
        return;
    }

    if (a == b) {
        if (n % a == 0) {
            cout << "Yes" << endl;
        } else {
            cout << "No" << endl;
        }
        return;
    }

    ll x = b / (b - a);
    if (n > x * a) {
        cout << "Yes" << endl;
        return;
    }

    ll low = 1, high = x + 1, ans = 1;
    while (low <= high) {
        ll mid = (low + high) / 2;
        if (mid * a < n) {
            low = mid + 1;
        } else {
            ans = mid;
            high = mid - 1;
        }
    }

    if (n > (ans - 1) * b && n < ans * a) {
        cout << "No" << endl;
    } else {
        cout << "Yes" << endl;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}
// END-OF-CODE