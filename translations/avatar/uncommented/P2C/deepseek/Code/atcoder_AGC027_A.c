#include <stdio.h>
#include <stdlib.h>

int main() {
    int nextInt() {
        int n;
        scanf("%d", &n);
        return n;
    }

    int *nextIntArray(int *n) {
        scanf("%d", n);
        int *arr = (int *)malloc(*n * sizeof(int));
        for (int i = 0; i < *n; i++) {
            scanf("%d", &arr[i]);
        }
        return arr;
    }

    int n, x;
    int *a;
    int ans = 0;

    n = nextInt();
    x = nextInt();
    a = nextIntArray(&n);

    qsort(a, n, sizeof(int), (int (*)(const void *, const void *))compare);

    if (a[0] > x) {
        printf("0\n");
        free(a);
        return 0;
    }

    for (int i = 0; i < n; i++) {
        if (a[i] > x) {
            x = 0;
            break;
        }
        x -= a[i];
        ans++;
    }

    if (x != 0) {
        ans--;
    }

    printf("%d\n", ans);
    free(a);
    return 0;
}

int compare(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}
