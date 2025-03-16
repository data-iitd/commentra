#include <stdio.h>
#include <stdlib.h>

int main() {
    int n;
    scanf("%d", &n);

    int *w = (int *)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        scanf("%d", &w[i]);
    }

    int c = 0;
    for (int i = 0; i < n; i++) {
        int count_i = 0;
        for (int j = 0; j < n; j++) {
            if (w[j] == w[i]) {
                count_i++;
            }
        }

        if (w[i] == 0) {
            c += count_i * (count_i - 1) / 2;
        } else {
            int count_neg_i = 0;
            for (int j = 0; j < n; j++) {
                if (w[j] == -w[i]) {
                    count_neg_i++;
                }
            }
            c += count_i * count_neg_i;
        }
    }

    free(w);
    printf("%d\n", c / 2);
    return 0;
}
