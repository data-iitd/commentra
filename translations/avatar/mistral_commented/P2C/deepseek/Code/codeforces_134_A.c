#include <stdio.h>
#include <stdlib.h>

int main() {
    int n;
    scanf("%d", &n);

    int w[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &w[i]);
    }

    int d[n];
    int d_size = 0;

    for (int i = 0; i < n; i++) {
        int sum = 0;
        for (int j = 0; j < n; j++) {
            if (j != i) {
                sum += w[j];
            }
        }
        if (sum % (n - 1) == 0 && sum / (n - 1) == w[i]) {
            d[d_size++] = i + 1;
        }
    }

    printf("%d\n", d_size);
    for (int i = 0; i < d_size; i++) {
        printf("%d ", d[i]);
    }
    printf("\n");

    return 0;
}
