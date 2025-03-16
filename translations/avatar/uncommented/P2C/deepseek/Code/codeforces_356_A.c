#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    int out[n];
    int comp[n];
    for (int i = 0; i < n; i++) {
        out[i] = 0;
        comp[i] = i + 2;
    }
    for (int i = 0; i < m; i++) {
        int l, r, x;
        scanf("%d %d %d", &l, &r, &x);
        int t = l - 1;
        while (t < r) {
            int next_val = comp[t];
            if (out[t] == 0 && t + 1 != x) {
                out[t] = x;
            }
            comp[t] = r > x ? x : r;
            t = next_val - 1;
        }
    }
    for (int i = 0; i < n; i++) {
        printf("%d ", out[i]);
    }
    printf("\n");
    return 0;
}
