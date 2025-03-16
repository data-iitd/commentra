
#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);

    int w[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &w[i]);
    }

    int x = 0;
    for (int i = 0; i < n; i++) {
        x += w[i];
    }

    int d_count = 0;
    int d[n];
    for (int i = 0; i < n; i++) {
        if ((x - w[i]) / (n - 1) == w[i]) {
            d[d_count] = i + 1;
            d_count++;
        }
    }

    printf("%d\n", d_count);
    for (int i = 0; i < d_count; i++) {
        printf("%d ", d[i]);
    }

    return 0;
}
