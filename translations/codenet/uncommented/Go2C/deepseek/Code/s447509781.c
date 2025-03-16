#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    int n;
    scanf("%d", &n);
    int64_t s[n];
    for (int i = 0; i < n; i++) {
        scanf("%lld", &s[i]);
    }
    int64_t m = 0;
    for (int c = 1; c < n - 1; c++) {
        int64_t f = 0;
        int u[n];
        memset(u, 0, sizeof(u));
        for (int k = 0; c < n - 1 - k * c; k++) {
            u[k * c] = 1;
            if (u[n - 1 - k * c]) break;
            f += s[n - 1 - k * c] + s[k * c];
            if (m < f) m = f;
        }
        for (int k = 0; k * c < n - 1; k++) u[k * c] = 0;
    }
    printf("%lld\n", m);
    return 0;
}
