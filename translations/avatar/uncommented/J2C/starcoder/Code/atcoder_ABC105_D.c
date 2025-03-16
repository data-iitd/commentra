#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <limits.h>
#include <stdbool.h>

#define MAX_N 100000

int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    int a[MAX_N];
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    int base = 0;
    long ans = 0;
    for (int i = 0; i < n; i++) {
        base = (base - a[i] % m + m) % m;
        int count = 0;
        for (int j = 0; j < m; j++) {
            int x = (base + a[i] + j) % m;
            count += (x == a[i] % m);
        }
        ans += count;
    }
    printf("%ld\n", ans);
    return 0;
}
