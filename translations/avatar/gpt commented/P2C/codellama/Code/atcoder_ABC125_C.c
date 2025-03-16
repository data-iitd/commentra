#include <stdio.h>
#include <stdlib.h>

int gcd(int a, int b) {
    if (b == 0) {
        return a;
    }
    return gcd(b, a % b);
}

void ruiseki_lr(int *array, int n, int *left, int *right) {
    int e = 0;
    int i;

    left[0] = e;
    right[n] = e;

    for (i = 0; i < n; i++) {
        left[i + 1] = gcd(left[i], array[i]);
    }

    for (i = n - 1; i >= 0; i--) {
        right[i] = gcd(right[i + 1], array[i]);
    }
}

int main() {
    int n;
    int *a;
    int *left;
    int *right;
    int i;
    int ans = 0;

    scanf("%d", &n);
    a = (int *)malloc(n * sizeof(int));
    left = (int *)malloc((n + 1) * sizeof(int));
    right = (int *)malloc((n + 1) * sizeof(int));

    for (i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    ruiseki_lr(a, n, left, right);

    for (i = 0; i < n; i++) {
        ans = max(gcd(left[i], right[i + 1]), ans);
    }

    printf("%d\n", ans);

    free(a);
    free(left);
    free(right);

    return 0;
}

