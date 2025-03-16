
#include <stdio.h>
#include <stdlib.h>

int gcd(int a, int b) {
    if (b == 0) {
        return a;
    }
    return gcd(b, a % b);
}

int ruiseki_lr(int *array, int n) {
    int e = 0;
    int *left = (int *)malloc((n + 1) * sizeof(int));
    int *right = (int *)malloc((n + 1) * sizeof(int));
    for (int i = 0; i < n + 1; i++) {
        left[i] = e;
        right[i] = e;
    }
    for (int i = 0; i < n; i++) {
        left[i + 1] = gcd(left[i], array[i]);
    }
    for (int i = n - 1; i >= 0; i--) {
        right[i] = gcd(right[i + 1], array[i]);
    }
    return left, right;
}

int main() {
    int n;
    scanf("%d", &n);
    int *a = (int *)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    int *left, *right;
    left, right = ruiseki_lr(a, n);
    int ans = 0;
    for (int i = 0; i < n; i++) {
        ans = max(gcd(left[i], right[i + 1]), ans);
    }
    printf("%d", ans);
    return 0;
}

