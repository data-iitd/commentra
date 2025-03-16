#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>

typedef long long ll;

// Function to calculate gcd
ll gcd(ll a, ll b) {
    return b ? gcd(b, a % b) : a;
}

// Function to calculate lcm
ll lcm(ll a, ll b) {
    return a / gcd(a, b) * b;
}

// Function to get prime factors of a number
void getPrimeFactor(ll n, ll *factors, ll *exponents, ll *count) {
    *count = 0;
    for (ll i = 2; i * i <= n; ++i) {
        while (n % i == 0) {
            factors[*count] = i;
            exponents[*count]++;
            n /= i;
            if (exponents[*count] == 1) (*count)++;
        }
    }
    if (n != 1) {
        factors[*count] = n;
        exponents[*count] = 1;
        (*count)++;
    }
}

// Function to check if a number is prime
bool IsPrimeNumber(ll num) {
    if (num <= 1) return false;
    if (num <= 3) return true;
    if (num % 2 == 0) return false;

    for (ll i = 3; i * i <= num; i += 2) {
        if (num % i == 0) {
            return false;
        }
    }
    return true;
}

// Function to find modular multiplicative inverse
long long modinv(long long a, long long m) {
    long long b = m, u = 1, v = 0;
    while (b) {
        long long t = a / b;
        a -= t * b; 
        long long temp = a; a = b; b = temp;
        u -= t * v; 
        temp = u; u = v; v = temp;
    }
    u %= m;
    if (u < 0) u += m;
    return u;
}

int main() {
    ll N, K;
    scanf("%lld %lld", &N, &K);

    ll *A = (ll *)malloc((N + 1) * sizeof(ll));
    for (ll i = 1; i <= N; i++) {
        scanf("%lld", &A[i]);
    }

    ll cur = 1;
    ll *dic = (ll *)malloc((N + 1) * sizeof(ll));
    for (ll i = 0; i <= N; i++) {
        dic[i] = -1;
    }

    bool flg = false;

    for (ll i = 1; i <= K; i++) {
        if (dic[cur] < 0 || flg) {
            dic[cur] = i;
            cur = A[cur];
        } else if (!flg) {
            ll tmp = K - (dic[cur] - 1);
            tmp %= i - dic[cur];
            i = K - tmp;
            flg = true;
        }
    }

    printf("%lld\n", cur);

    free(A);
    free(dic);
    return 0;
}
// <END-OF-CODE>
