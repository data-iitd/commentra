#include <stdio.h>
#include <stdlib.h>

#define MAX_N 200005

long long a[MAX_N];
long long pre[MAX_N];
long long last[MAX_N];

int main() {
    int n;
    scanf("%d", &n);

    for (int i = 1; i <= n; i++) {
        scanf("%lld", &a[i]);
        pre[i] = pre[i - 1] + a[i];
        last[i] = last[i + 1] + a[i];
    }

    long long sumpre = 0, sumlast = 0;

    for (int i = 1; i < n; i++) {
        sumpre += a[i];
        pre[i] = sumpre;
    }

    for (int i = n; i > 0; i--) {
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
}

