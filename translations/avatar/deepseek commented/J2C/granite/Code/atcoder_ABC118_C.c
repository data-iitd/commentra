

#include <stdio.h>
#include <stdlib.h>

int main() {
    int n;
    scanf("%d", &n);
    int *a = (int *)malloc(n * sizeof(int));
    if (n == 1) {
        scanf("%d", &a[0]);
        printf("%d\n", a[0]);
        free(a);
        return 0;
    }
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    qsort(a, n, sizeof(int), cmpfunc);
    if (a[n - 1] == 0) {
        printf("0\n");
        free(a);
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
    free(a);
    return 0;
}

int cmpfunc(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}

int *func(int *a, int n) {
    int min = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] == 0) {
            for (int j = i; j < n - 1; j++) {
                a[j] = a[j + 1];
            }
            n--;
            i--;
        } else {
            if (min!= 0) {
                a[i] = a[i] % min;
                if (a[i] == 1) {
                    printf("1\n");
                    exit(0);
                }
            } else {
                min = a[i];
            }
        }
    }
    qsort(a, n, sizeof(int), cmpfunc);
    return a;
}

