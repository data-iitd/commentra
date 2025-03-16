
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
#define tr(it, x) for(auto it = x.begin(); it!= x.end(); it++)
#define PI 3.1415926535897932384626433832795

typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<pii> vpii;
typedef vector<pll> vpll;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    int l, r;
    cin >> l >> r;

    int id = 0;
    for (int i = 1; i < n; i++) {
        int li, ri;
        cin >> li >> ri;

        if (li <= l && r <= ri) {
            id = i;
        } else if (li < l || r < ri) {
            id = n;
        }

        l = min(l, li);
        r = max(r, ri);
    }

    cout << (id == n? -1 : id + 1) << endl;

    return 0;
}
