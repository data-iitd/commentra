

#include <stdio.h>
#include <stdlib.h>

int main() {
    int n;
    scanf("%d", &n);

    int *w = (int *)malloc(n * sizeof(int));
    int *count = (int *)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        scanf("%d", &w[i]);
        count[i] = 0;
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (w[i] == w[j]) {
                count[i]++;
            }
        }
    }

    int c = 0;
    for (int i = 0; i < n; i++) {
        if (w[i] == 0) {
            c += count[i] * (count[i] - 1);
        } else {
            for (int j = 0; j < n; j++) {
                if (w[i] == -w[j]) {
                    c += count[i] * count[j];
                }
            }
        }
    }

    printf("%d\n", c / 2);

    free(w);
    free(count);

    return 0;
}
