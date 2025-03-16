#include <stdio.h>
#include <stdlib.h>

int compare(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}

int bisect_left(int *arr, int size, int value) {
    int low = 0, high = size;
    while (low < high) {
        int mid = (low + high) / 2;
        if (arr[mid] < value) {
            low = mid + 1;
        } else {
            high = mid;
        }
    }
    return low;
}

int bisect_right(int *arr, int size, int value) {
    int low = 0, high = size;
    while (low < high) {
        int mid = (low + high) / 2;
        if (arr[mid] <= value) {
            low = mid + 1;
        } else {
            high = mid;
        }
    }
    return low;
}

int main() {
    int n;
    scanf("%d", &n);
    int *l = malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        scanf("%d", &l[i]);
    }

    qsort(l, n, sizeof(int), compare);
    long long ans = 0;

    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            int a = l[i];
            int b = l[j];
            int right = bisect_left(l, n, a + b);
            int left = bisect_right(l, n, (a > b ? a - b : b - a));
            int tmp = right - left;

            if (left <= i && i < right) {
                tmp--;
            }
            if (left <= j && j < right) {
                tmp--;
            }
            ans += (tmp > 0) ? tmp : 0;
        }
    }

    printf("%lld\n", ans / 3);
    free(l);
    return 0;
}
// <END-OF-CODE>
