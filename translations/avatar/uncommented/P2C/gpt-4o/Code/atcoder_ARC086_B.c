#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MOD 1000000007

int my_sign(int x) {
    return (x > 0) - (x < 0);
}

int main() {
    int N;
    scanf("%d", &N);
    
    int *a = (int *)malloc(N * sizeof(int));
    for (int i = 0; i < N; i++) {
        scanf("%d", &a[i]);
    }

    int max_val = 0;
    int max_sign = 0;
    int max_index = -1;

    for (int i = 0; i < N; i++) {
        if (abs(a[i]) > max_val) {
            max_val = abs(a[i]);
            max_sign = my_sign(a[i]);
            max_index = i;
        }
    }

    if (max_sign == 0) {
        printf("0\n");
    } else {
        printf("%d\n", 2 * N - 1);
        for (int i = 0; i < N; i++) {
            printf("%d %d\n", max_index + 1, i + 1);
        }
        if (max_sign == 1) {
            for (int i = 0; i < N - 1; i++) {
                printf("%d %d\n", i + 1, i + 2);
            }
        } else {
            for (int i = N - 1; i > 0; i--) {
                printf("%d %d\n", i + 1, i);
            }
        }
    }

    free(a);
    return 0;
}

// <END-OF-CODE>
