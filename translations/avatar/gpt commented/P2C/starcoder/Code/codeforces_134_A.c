#include <stdio.h>
#include <stdlib.h>

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
    int d[n];
    for (int i = 0; i < n; i++) {
        if ((x - w[i]) / (n - 1) == w[i]) {
            d[i] = i + 1;
        }
    }
    printf("%d\n", i + 1);
    for (int i = 0; i < n; i++) {
        printf("%d ", d[i]);
    }
    printf("\n");
    return 0;
}

