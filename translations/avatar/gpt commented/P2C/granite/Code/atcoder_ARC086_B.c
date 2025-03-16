
#include <stdio.h>
#include <stdlib.h>

int main() {
    int N = 0;
    scanf("%d", &N);

    int *a = (int *)malloc(sizeof(int) * N);
    for (int i = 0; i < N; i++) {
        scanf("%d", &a[i]);
    }

    int max_val = 0;
    int max_sign = 0;
    int max_index = -1;

    for (int i = 0; i < N; i++) {
        int abs_a = abs(a[i]);
        if (abs_a > max_val) {
            max_val = abs_a;
            max_sign = (a[i] > 0) - (a[i] < 0);
            max_index = i;
        }
    }

    if (max_sign == 0) {
        printf("0\n");
    } else if (max_sign == 1) {
        printf("%d\n", 2 * N - 1);
        for (int i = 0; i < N; i++) {
            printf("%d %d\n", max_index + 1, i + 1);
        }
        for (int i = 0; i < N - 1; i++) {
            printf("%d %d\n", i + 1, i + 2);
        }
    } else {
        printf("%d\n", 2 * N - 1);
        for (int i = 0; i < N; i++) {
            printf("%d %d\n", max_index + 1, i + 1);
        }
        for (int i = N - 1; i > 0; i--) {
            printf("%d %d\n", i + 1, i);
        }
    }

    free(a);
    return 0;
}
