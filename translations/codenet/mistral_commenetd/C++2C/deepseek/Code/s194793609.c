#include <stdio.h>
#include <stdlib.h>

int main() {
    int n;
    scanf("%d", &n);

    long long a[n];
    for (int i = 0; i < n; i++) {
        scanf("%lld", &a[i]);
    }

    long long abs_a[n];
    for (int i = 0; i < n; i++) {
        abs_a[i] = a[i];
        if (abs_a[i] < 0) {
            abs_a[i] = -abs_a[i];
        }
    }

    long long ans = 0, min = abs_a[0];
    for (int i = 0; i < n; i++) {
        ans += abs_a[i];
        if (min > abs_a[i]) {
            min = abs_a[i];
        }
    }

    int num_negative = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] < 0) {
            num_negative++;
        }
    }

    if (num_negative % 2) {
        ans -= min * 2;
    }

    printf("%lld\n", ans);
}

