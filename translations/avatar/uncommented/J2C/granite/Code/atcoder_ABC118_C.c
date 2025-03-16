
#include <stdio.h>
#include <stdlib.h>

int main() {
    int n;
    scanf("%d", &n);
    int *a = (int *)malloc(n * sizeof(int));
    if (n == 1) {
        scanf("%d", &a[0]);
        printf("%d\n", a[0]);
        return 0;
    }
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    qsort(a, n, sizeof(int));
    if (a[n - 1] == 0) {
        printf("0\n");
        return 0;
    }
    int ans = 0;
    while (1) {
        if (n == 1) {
            ans = a[0];
            break;
        }
        a = func(a, n);
        n = 0;
        for (int i = 0; i < n; i++) {
            if (a[i]!= 0) {
                a[n++] = a[i];
            }
        }
    }
    printf("%d\n", ans);
    return 0;
}

int *func(int *a, int n) {
    int min = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] == 0) {
            continue;
        }
        if (min == 0) {
            min = a[i];
        } else {
            a[i] = a[i] % min;
            if (a[i] == 1) {
                printf("1\n");
                exit(0);
            }
        }
    }
    qsort(a, n, sizeof(int));
    return a;
}

// 