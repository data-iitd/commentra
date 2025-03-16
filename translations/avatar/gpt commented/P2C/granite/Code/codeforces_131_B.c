
#include <stdio.h>
#include <stdlib.h>

int main() {
    int n;
    scanf("%d", &n);

    int *w = (int *)malloc(n * sizeof(int));
    int i;
    for (i = 0; i < n; i++) {
        scanf("%d", &w[i]);
    }

    int *count = (int *)malloc(n * sizeof(int));
    for (i = 0; i < n; i++) {
        count[i] = 0;
    }

    for (i = 0; i < n; i++) {
        count[w[i] + n]++;
    }

    int c = 0;
    for (i = 0; i < n; i++) {
        if (i == 0) {
            c += count[i] * (count[i] - 1);
        } else {
            c += count[i] * count[n - i];
        }
    }

    printf("%d\n", c / 2);

    free(w);
    free(count);

    return 0;
}
