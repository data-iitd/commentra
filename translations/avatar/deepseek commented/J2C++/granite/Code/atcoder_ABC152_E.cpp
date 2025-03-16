

#include <bits/stdc++.h> 
using namespace std; 

typedef long long ll; 
const ll mod = 1e9 + 7; 

ll modpow(ll x, ll n) { 
    ll res = 1; 
    while (n > 0) { 
        if (n & 1) res = res * x % mod; 
        x = x * x % mod; 
        n >>= 1; 
    } 
    return res; 
} 

ll modinv(ll x) { 
    return modpow(x, mod - 2); 
} 

ll moddiv(ll a, ll b) { 
    return (a * modinv(b)) % mod; 
} 

int main() { 
    int N; 
    cin >> N; 
    vector<int> A(N); 
    for (int i = 0; i < N; i++) { 
        cin >> A[i]; 
    } 
    ll lcm = 1; 
    for (int a : A) { 
        lcm = lcm / __gcd(lcm, a) * a; 
    } 
    ll ans = 0; 
    for (int a : A) { 
        ans = (ans + moddiv(lcm, a)) % mod; 
    } 
    cout << ans << endl; 
    return 0; 
} 

