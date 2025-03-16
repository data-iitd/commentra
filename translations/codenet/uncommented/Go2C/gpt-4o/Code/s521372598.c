#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_N 100000

int compare(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}

int abs(int n) {
    return n < 0 ? -n : n;
}

void solve() {
    int n;
    scanf("%d", &n);
    
    int as[MAX_N];
    for (int i = 0; i < n; i++) {
        scanf("%d", &as[i]);
    }

    int xs[MAX_N];
    for (int i = 0; i < n; i++) {
        xs[i] = as[i] - i + 1;
    }

    qsort(xs, n, sizeof(int), compare);

    int b = xs[n / 2];
    long long ans = 0;
    for (int i = 0; i < n; i++) {
        ans += abs(xs[i] - b);
    }
    
    printf("%lld\n", ans);
}

int main() {
    solve();
    return 0;
}

// <END-OF-CODE>
