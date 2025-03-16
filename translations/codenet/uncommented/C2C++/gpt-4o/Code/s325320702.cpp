#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <cassert>
#include <cctype>

typedef long long ll;
#define rep(i, l, r) for (ll i = (l); i < (r); i++)
#define repp(i, l, r, k) for (ll i = (l); i < (r); i += (k))
#define rrep(i, l, r) for (ll i = (l); i >= (r); i--)
#define INF (1LL << 60)
#define MOD1 1000000007
#define MOD2 998244353
#define MAX_N (1 << 20)
#define YES std::cout << "Yes\n"
#define NO std::cout << "No\n"
#define PN std::cout << "\n"
#define charsize 100005 //10^5+5
#define PI 3.141592653589793238

void cin(ll &n) { std::cin >> n; }

int main() {
    ll l, r, d;
    ll ans = 0;
    cin(l);
    cin(r);
    cin(d);

    rep(i, l, r + 1) {
        if (i % d == 0) ans++;
    }
    std::cout << ans << "\n";
    return 0;
}

// <END-OF-CODE>
