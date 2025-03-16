#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, k, l, r, sa, sk;
    scanf("%d %d %d %d %d %d", &n, &k, &l, &r, &sa, &sk);

    int *ans = (int *)malloc(sizeof(int) * n);
    for (int i = 0; i < k; i++) {
        ans[i] = sk / k + 1;
        if (i < sk % k) {
            ans[i]++;
        }
    }
    for (int i = k; i < n; i++) {
        ans[i] = (sa - sk) / (n - k) + 1;
        if (i < (sa - sk) % (n - k)) {
            ans[i]++;
        }
    }

    for (int i = 0; i < n; i++) {
        printf("%d ", ans[i]);
    }
    printf("