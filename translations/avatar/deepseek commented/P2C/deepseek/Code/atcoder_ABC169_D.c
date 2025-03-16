#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

#define INF 999999999999999999999999
#define MOD 1000000007

typedef long long ll;

ll n;

ll gcd(ll a, ll b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}

void prime_factorize(ll n, ll *factors, ll *count, ll *size) {
    ll i = 2;
    while (i * i <= n) {
        if (n % i == 0) {
            factors[*size] = i;
            count[*size] = 0;
            while (n % i == 0) {
                n /= i;
                count[*size]++;
            }
            (*size)++;
        }
        i++;
    }
    if (n != 1) {
        factors[*size] = n;
        count[*size] = 1;
        (*size)++;
    }
}

int main() {
    scanf("%lld", &n);
    if (n == 1) {
        printf("0\n");
        return 0;
    }

    ll factors[100000];
    ll count[100000];
    ll size = 0;

    prime_factorize(n, factors, count, &size);

    ll ans = 0;
    for (ll i = 0; i < size; i++) {
        ll x = count[i];
        for (ll j = 1; ; j++) {
            if (x >= j) {
                x -= j;
                ans++;
            } else {
                break;
            }
        }
    }

    printf("%lld\n", ans);
    return 0;
}
