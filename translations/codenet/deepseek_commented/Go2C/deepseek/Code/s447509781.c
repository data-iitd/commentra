#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    int n;
    scanf("%d", &n);
    int *s = (int *)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        scanf("%d", &s[i]);
    }
    bool *u = (bool *)calloc(n, sizeof(bool));
    int64_t m = 0, f = 0;

    for (int c = 1; c < n - 1; c++) {
        f = 0;
        for (int k = 0; k * c < n - 1; k++) {
            u[k * c] = true;
            if (u[n - 1 - k * c]) break;
            f += s[n - 1 - k * c] + s[k * c];
            if (m < f) m = f;
        }
        for (int k = 0; k * c < n - 1; k++) {
            u[k * c] = false;
        }
    }
    printf("%lld\n", m);
    free(s);
    free(u);
    return 0;
}
