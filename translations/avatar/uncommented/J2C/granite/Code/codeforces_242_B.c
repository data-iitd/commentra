
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int main() {
    int n;
    scanf("%d", &n);
    int *a = (int *)malloc(n * sizeof(int));
    int *b = (int *)malloc(n * sizeof(int));
    int left = INT_MAX, right = 0;
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
        scanf("%d", &b[i]);
        if (a[i] < left) {
            left = a[i];
        }
        if (b[i] > right) {
            right = b[i];
        }
    }
    for (int i = 0; i < n; i++) {
        if (a[i] == left && b[i] == right) {
            printf("%d\n", i + 1);
            return 0;
        }
    }
    printf("-1\n");
    return 0;
}
