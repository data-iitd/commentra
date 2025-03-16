#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef long long ll;

ll gcd(ll a, ll b) {
    return b ? gcd(b, a % b) : a;
}

ll lcm(ll a, ll b) {
    return a / gcd(a, b) * b;
}

<<<<<<< HEAD
void getPrimeFactor(ll n, ll *factors, ll *counts, ll *size) {
    *size = 0;
    for (ll i = 2; i * i <= n; ++i) {
        while (n % i == 0) {
            factors[*size] = i;
            counts[*size]++;
            n /= i;
            if (counts[*size] == 1) (*size)++;
        }
    }
    if (n != 1) {
        factors[*size] = n;
        counts[*size] = 1;
        (*size)++;
    }
=======
void getPrimeFactor(ll n, ll *res, ll *count) {
    for (ll i = 2; i * i <= n; ++i) {
        while (n % i == 0) {
            res[i]++;
            n /= i;
        }
    }
    if (n != 1) res[n] = 1;
>>>>>>> 98c87cb78a (data updated)
}

int IsPrimeNumber(ll num) {
    if (num <= 2) return 1;
    else if (num % 2 == 0) return 0;

    double sqrtNum = sqrt(num);
    for (int i = 3; i <= sqrtNum; i += 2) {
        if (num % i == 0) {
            return 0;
        }
    }

    return 1;
}

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
<<<<<<< HEAD
    for (ll i = 0; i <= N; i++) dic[i] = -1;

=======
    for (ll i = 0; i <= N; i++) {
        dic[i] = -1;
    }
    
>>>>>>> 98c87cb78a (data updated)
    int flg = 0;
    for (ll i = 1; i <= K; i++) {
        if (dic[cur] < 0 || flg) {
            dic[cur] = i;
            cur = A[cur];
        } else if (!flg) {
            ll tmp = K - (dic[cur] - 1);
            tmp %= i - dic[cur];
            i = K - tmp;
            flg = 1;
        }
    }

    printf("%lld\n", cur);
<<<<<<< HEAD

=======
    
>>>>>>> 98c87cb78a (data updated)
    free(A);
    free(dic);
    return 0;
}

// <END-OF-CODE>
