
#include <stdio.h>
#include <stdlib.h>

typedef long long ll;

ll combi(int n, int k) {
    ll min = (ll)(k-1) * k / 2;
    ll max = (ll)(2*n-k+1) * k / 2;
    return max - min + 1;
}

ll abs(ll x) {
    if (x >= 0) {
        return x;
    }
    return -x;
}

ll min(ll x, ll y) {
    if (x < y) {
        return x;
    }
    return y;
}

ll max(ll x, ll y) {
    if (x > y) {
        return x;
    }
    return y;
}

ll pow(ll base, unsigned int exponent) {
    ll answer = 1;
    for (unsigned int i = 0; i < exponent; i++) {
        answer *= base;
    }
    return answer;
}

ll abs64(ll x) {
    if (x >= 0) {
        return x;
    }
    return -x;
}

ll min64(ll x, ll y) {
    if (x < y) {
        return x;
    }
    return y;
}

ll max64(ll x, ll y) {
    if (x > y) {
        return x;
    }
    return y;
}

ll pow64(ll base, unsigned int exponent) {
    ll answer = 1;
    for (unsigned int i = 0; i < exponent; i++) {
        answer *= base;
    }
    return answer;
}

int main() {
    int n, k;
    scanf("%d %d", &n, &k);

    ll total = 0;
    for (int i = k; i <= n+1; i++) {
        total += combi(n, i);
        total = total % (pow64(10, 9) + 7);
    }
    printf("%lld\n", total);

    return 0;
}
