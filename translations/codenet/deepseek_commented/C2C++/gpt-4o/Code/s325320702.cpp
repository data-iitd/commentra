#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <cassert>
#include <cctype>

typedef long long ll;
#define rep(i,l,r) for(ll i=(l); i<(r); i++)
#define INF (1LL<<60)
#define MOD1 1000000007
#define MOD2 998244353

// Utility Functions
void cin(ll &n) { std::cin >> n; }

// Main Function
int main() {
    ll l, r, d;
    ll ans = 0;
    cin(l);
    cin(r);
    cin(d);
    rep(i, l, r + 1) {
        if (i % d == 0) ans++;
    }
    std::cout << ans << std::endl;
    return 0;
}

// <END-OF-CODE>
