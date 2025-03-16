

#include <iostream>

using namespace std;

typedef long long ll;

ll solve(ll n) {
    ll s = (1 + n) * n / 2;
    ll t = 1;
    while (t <= n) {
        s -= 2 * t;
        t *= 2;
    }
    return s;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        ll n;
        cin >> n;
        cout << solve(n) << endl;
    }
    return 0;
}

