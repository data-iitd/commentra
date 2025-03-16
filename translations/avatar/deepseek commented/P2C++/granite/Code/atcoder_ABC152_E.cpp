
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll MOD = 1e9 + 7;

ll gcd(ll a, ll b) { return b? gcd(b, a % b) : a; }

ll lcm(ll a, ll b) { return a / gcd(a, b) * b; }

int main() {
    int N;
    cin >> N;
    vector<ll> A(N);
    for (int i = 0; i < N; i++) cin >> A[i];

    ll _lcm = 1;
    for (int i = 0; i < N; i++) _lcm = lcm(_lcm, A[i]);

    ll ans = _lcm;
    for (int i = 0; i < N; i++) ans = ans * pow(A[i], MOD - 2, MOD) % MOD;

    cout << ans << endl;

    return 0;
}

