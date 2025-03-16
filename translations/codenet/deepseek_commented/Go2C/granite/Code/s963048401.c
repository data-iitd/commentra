
#include <stdio.h>
#include <stdlib.h>

int main() {
    int n;
    scanf("%d", &n);
    int *as = (int *)malloc(sizeof(int) * n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &as[i]);
    }

    int *xs = (int *)malloc(sizeof(int) * n);
    xs[0] = as[0];
    int xs_len = 1;
    for (int j = 1; j < n; j++) {
        int idx = 0;
        while (idx < xs_len && xs[idx] < as[j]) {
            idx++;
        }
        if (idx == xs_len) {
            xs = (int *)realloc(xs, sizeof(int) * (xs_len + 1));
            xs[xs_len] = as[j];
            xs_len++;
        } else {
            xs[idx] = as[j];
        }
    }

    printf("%d\n", xs_len);

    free(as);
    free(xs);

    return 0;
}
