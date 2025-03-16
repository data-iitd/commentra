#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>

using namespace std;

long long modPow(long long b, long long e, long long mod) {
    long long ans = 1;
    long long x = b % mod;
    while (e != 0) {
        if (e & 1) {
            ans = (ans * x) % mod;
        }
        x = (x * x) % mod;
        e >>= 1;
    }
    return ans;
}

long long modInv(long long x, long long mod) {
    return modPow(x, mod - 2, mod);
}

long long modDiv(long long a, long long b, long long mod) {
    return (a % mod) * modInv(b, mod) % mod;
}

int main() {
    int N;
    cin >> N;
    vector<int> A(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }

    long long lcm = 1;
    long long mod = 1000000007;

    for (int ai : A) {
        lcm = lcm / __gcd(lcm, (long long)ai) * ai;
    }

    long long modLcm = lcm % mod;
    long long ans = 0;

    for (int ai : A) {
        ans = (ans + modDiv(modLcm, ai, mod)) % mod;
    }

    cout << ans << endl;

    return 0;
}

// <END-OF-CODE>
