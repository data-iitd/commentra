#include <stdio.h>
#include <stdlib.h>

int compare(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}

int main() {
    int n, *l, i, j, k, ans = 0;
    scanf("%d", &n);
    l = (int*)malloc(n * sizeof(int));
    for (i = 0; i < n; i++) {
        scanf("%d", &l[i]);
    }
    qsort(l, n, sizeof(int), compare);

    for (i = 0; i < n; i++) {
        for (j = i + 1; j < n; j++) {
            int a = l[i];
            int b = l[j];
            int left = 0, right = n, tmp;

            while (left < right) {
                int mid = left + (right - left) / 2;
                if (l[mid] < a + b) {
                    left = mid + 1;
                } else {
                    right = mid;
                }
            }
            right = left;

            left = 0, right = n;
            while (left < right) {
                int mid = left + (right - left) / 2;
                if (l[mid] <= max(a - b, b - a)) {
                    left = mid + 1;
                } else {
                    right = mid;
                }
            }
            tmp = right - left;

            if (left <= i && i < right) tmp--;
            if (left <= j && j < right) tmp--;
            ans += tmp;
        }
    }
    printf("%d\n", ans / 3);
    free(l);
    return 0;
}
