#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>
#include <assert.h>
#include <limits.h>
#include <ctype.h>
#include <time.h>

int main() {
    int n;
    scanf("%d", &n);
    int *l = malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        scanf("%d", l + i);
    }
    qsort(l, n, sizeof(int), cmpfunc);
    int ans = 0;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            int a = l[i];
            int b = l[j];
            int right = bisect_left(l, a + b);
            int left = bisect_right(l, max(a - b, b - a));
            int tmp = max(0, right - left);
            if (left <= i < right) {
                tmp -= 1;
            }
            if (left <= j < right) {
                tmp -= 1;
            }
            ans += tmp;
        }
    }
    printf("%d\n", ans / 3);
    return 0;
}

