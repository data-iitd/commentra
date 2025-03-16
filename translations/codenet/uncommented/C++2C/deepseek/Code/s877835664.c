#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include <string.h>

typedef long long ll;

ll gcd(ll a, ll b) {
    return b ? gcd(b, a % b) : a;
}

ll lcm(ll a, ll b) {
    return a / gcd(a, b) * b;
}

typedef struct {
    ll first;
    ll second;
} pair;

pair* getPrimeFactor(ll n) {
    pair* res = (pair*)malloc(sizeof(pair));
    res->first = 0;
    res->second = 0;
    for (ll i = 2; i * i <= n; ++i) {
        while (n % i == 0) {
            res->first = i;
            res->second++;
            n /= i;
        }
    }
    if (n != 1) {
        res->first = n;
        res->second = 1;
    }
    return res;
}

bool IsPrimeNumber(ll num) {
    if (num <= 2) return true;
    else if (num % 2 == 0) return false;

    ll sqrtNum = (ll)sqrt(num);
    for (ll i = 3; i <= sqrtNum; i += 2) {
        if (num % i == 0) {
            return false;
        }
    }

    return true;
}

ll modinv(ll a, ll m) {
    ll b = m, u = 1, v = 0;
    while (b) {
        ll t = a / b;
        a -= t * b;
        ll temp = a; a = b; b = temp;
        u -= t * v;
        temp = u; u = v; v = temp;
    }
    u %= m;
    if (u < 0) u += m;
    return u;
}

#define rep(i, s, e) for(ll i = s; i < e; i++)
#define repeq(i, s, e) for(ll i = s; i <= e; i++)

int main() {
    ll N, K;
    scanf("%lld %lld", &N, &K);

    ll* A = (ll*)malloc((N + 1) * sizeof(ll));
    repeq(i, 1, N) {
        scanf("%lld", &A[i]);
    }

    ll cur = 1;
    ll* dic = (ll*)malloc((N + 1) * sizeof(ll));
    bool flg = false;
    repeq(i, 1, K) {
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
