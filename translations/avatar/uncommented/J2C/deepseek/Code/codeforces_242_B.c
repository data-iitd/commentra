#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define INF INT_MAX

int main() {
    int n;
    scanf("%d", &n);
    int *a = (int *)malloc(n * sizeof(int));
    int *b = (int *)malloc(n * sizeof(int));
    int left = INF, right = 0;

    for (int i = 0; i < n; i++) {
        scanf("%d %d", &a[i], &b[i]);
        if (a[i] < left) left = a[i];
        if (b[i] > right) right = b[i];
    }

    for (int i = 0; i < n; i++) {
        if (a[i] == left && b[i] == right) {
            printf("%d\n", i + 1);
            free(a);
            free(b);
            return 0;
        }
    }

    printf("-1\n");
    free(a);
    free(b);
    return 0;
}
