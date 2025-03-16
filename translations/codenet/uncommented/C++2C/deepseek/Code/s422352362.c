#include <stdio.h>
#include <stdlib.h>

int main() {
    int n;
    scanf("%d", &n);
    long long a[200005];
    long long pre[200005];
    long long last[200005];

    for (int i = 1; i <= n; i++) {
        scanf("%lld", &a[i]);
    }

    long long sumpre = 0, sumlast = 0;
    for (int i = 1; i < n; i++) {
        sumpre += a[i];
        pre[i] = sumpre;
    }

    for (int i = n; i > 1; i--) {
        sumlast += a[i];
        last[i] = sumlast;
    }

    long long d = (1LL << 60);
    for (int i = 1; i < n; i++) {
        long long diff = abs(pre[i] - last[i + 1]);
        if (diff < d) {
            d = diff;
        }
    }

    printf("%lld\n", d);
    return 0;
}
