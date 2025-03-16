#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);
    int result = 0;
    int h[n];
    int g[n];

    for (int i = 0; i < n; i++) {
        scanf("%d", &h[i]);
        scanf("%d", &g[i]);
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

// <END-OF-CODE>
