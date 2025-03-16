#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);

    int lista[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &lista[i]);
    }

    for (int i = 0; i < n; i++) {
        if (i == 0) {
            printf("%d %d\n", lista[i + 1] - lista[i], lista[n - 1] - lista[i]);
            continue;
        }

        if (i == n - 1) {
            printf("%d %d\n", lista[n - 1] - lista[n - 2], lista[n - 1] - lista[0]);
            continue;
        }

        if (lista[i] - lista[i - 1] > lista[i + 1] - lista[i]) {
            printf("%d ", lista[i + 1] - lista[i]);
        } else {
            printf("%d ", lista[i] - lista[i - 1]);
        }

        if (lista[n - 1] - lista[i] > lista[i] - lista[0]) {
            printf("%d\n", lista[n - 1] - lista[i]);
        } else {
            printf("%d\n", lista[i] - lista[0]);
        }
    }

    return 0;
}

