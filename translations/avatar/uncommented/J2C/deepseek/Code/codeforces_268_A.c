#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, result = 0;
    scanf("%d", &n);
    int h[n], g[n];

    for (int i = 0; i < n; i++) {
        scanf("%d %d", &h[i], &g[i]);
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (h[i] == g[j]) {
                result++;
            }
        }
    }

    printf("%d\n", result);
    return 0;
}

