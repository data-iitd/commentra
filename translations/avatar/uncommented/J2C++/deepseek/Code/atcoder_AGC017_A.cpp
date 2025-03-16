#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

typedef long long ll;

vector<ll> fact(51);

void init() {
    fact[0] = 1;
    for (int i = 1; i <= 50; i++) {
        fact[i] = fact[i - 1] * i;
    }
}

ll C(int n, int m) {
    return fact[m] / (fact[n] * fact[m - n]);
}

int main() {
    init();
    int n, p;
    cin >> n >> p;
    int k0 = 0, k1 = 0;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        if (x % 2 == 1) k1++;
        else k0++;
    }
    ll ans = 1;
    for (int i = 0; i < k0; i++) ans *= 2;
    if (p == 0) {
        ll add = 0;
        for (int i = 0; i <= k1; i += 2) add += C(i, k1);
        ans *= add;
        cout << ans << endl;
    } else {
        ll add = 0;
        for (int i = 1; i <= k1; i += 2) add += C(i, k1);
        ans *= add;
        cout << ans << endl;
    }
    return 0;
}
