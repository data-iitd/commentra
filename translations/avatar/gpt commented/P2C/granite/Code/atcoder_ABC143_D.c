
#include <stdio.h>
#include <stdlib.h>

int main() {
    int n;
    scanf("%d", &n);

    int *l = (int *)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        scanf("%d", &l[i]);
    }

    qsort(l, n, sizeof(int), cmpfunc);

    int ans = 0;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            int a = l[i], b = l[j];
            int left = lower_bound(l, l + n, max(a - b, b - a)) - l;
            int right = upper_bound(l, l + n, a + b) - l;
            int tmp = right - left;
            if (left <= i && i < right) tmp--;
            if (left <= j && j < right) tmp--;
            ans += tmp;
        }
    }

    printf("%d\n", ans / 3);

    free(l);
    return 0;
}

int cmpfunc(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}

