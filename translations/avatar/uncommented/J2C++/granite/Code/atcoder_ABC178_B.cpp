
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll modPower(ll x, ll y, ll mod) {
    ll res = 1;
    x %= mod;
    if (x == 0) return 0;
    while (y > 0) {
        if (y % 2 == 1) {
            res = (res * x) % mod;
        }
        y = y >> 1;
        x = (x * x) % mod;
    }
    return res;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    ll a[4];
    for (int i = 0; i < 4; i++) {
        cin >> a[i];
    }

    cout << max({a[0] * a[2], a[1] * a[3], a[0] * a[3], a[1] * a[2]}) << endl;

    return 0;
}
//END-OF-CODE