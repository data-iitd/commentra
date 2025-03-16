#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    int *out = (int *)calloc(n, sizeof(int));
    int *comp = (int *)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        comp[i] = i + 2;
    }

    for (int i = 0; i < m; i++) {
        int l, r, x;
        scanf("%d %d %d", &l, &r, &x);

        int t = l;
        while (t <= r) {
            int next_val = comp[t - 1];
            if (out[t - 1] == 0 && t != x) {
                out[t - 1] = x;
            }
            comp[t - 1] = r + 1;
            if (t >= x) {
                comp[t - 1] = x;
            }
            t = next_val;
        }
    }

    for (int i = 0; i < n; i++) {
        printf("%d ", out[i]);
    }
    printf("\n");

    free(out);
    free(comp);
    return 0;
}
