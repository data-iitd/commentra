#include <stdio.h>

int gcd(int a, int b) {
    if (b == 0) {
        return a;
    }
    return gcd(b, a % b);
}

void ruiseki_lr(int* array, int n, int* left, int* right) {
    int op(int a, int b) {
        return gcd(a, b);
    }
    int e = 0;
    left[0] = e;
    for (int i = 0; i < n; i++) {
        left[i + 1] = op(left[i], array[i]);
    }
    right[n] = e;
    for (int i = n - 1; i >= 0; i--) {
        right[i] = op(right[i + 1], array[i]);
    }
}

int main() {
    int n;
    scanf("%d", &n);
    int a[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    int left[n + 1];
    int right[n + 1];
    ruiseki_lr(a, n, left, right);
    int ans = 0;
    for (int i = 0; i < n; i++) {
        int temp = gcd(left[i], right[i + 1]);
        if (temp > ans) {
            ans = temp;
        }
    }
    printf("%d\n", ans);
    return 0;
}
