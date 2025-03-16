#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;
    int A[N];
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }

    long long lcm = 1;
    for (int i = 0; i < N; i++) {
        lcm = lcm / __gcd(lcm, A[i]) * A[i];
    }

    long long mod = 1000000007;
    long long modLcm = lcm % mod;

    long long ans = 0;
    for (int i = 0; i < N; i++) {
        ans = (ans + modDiv(modLcm, A[i], mod)) % mod;
    }

    cout << ans << "\n";
}

// A private method modDiv is used to perform modular division
long long modDiv(long long a, long long b, long long mod) {
    return (a % mod) * modInv(b, mod) % mod;
}

// A private method modInv is used to calculate the modular inverse of a number
long long modInv(long long x, long long mod) {
    return modPow(x, mod - 2, mod);
}

// A private method modPow is used to calculate the power of a number using modular arithmetic
long long modPow(long long b, long long e, long long mod) {
    long long ans = 1;
    long long x = b % mod;
    for (long long y = e; y!= 0; y >>= 1) {
        if ((y & 1) == 1) {
            ans = (ans * x) % mod;
        }
        x = (x * x) % mod;
    }
    return ans;
}

