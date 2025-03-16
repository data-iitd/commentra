#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, k, l, r, sa, sk;
    scanf("%d %d %d %d %d %d", &n, &k, &l, &r, &sa, &sk);
    int *ans = (int *)malloc(sizeof(int) * n);
    for (int i = 0; i < n; i++) {
        ans[i] = (sk > 0 && i < k)? (sk--, 1) : (sa--, 0);
    }
    for (int i = 0; i < n; i++) {
        printf("%d ", ans[i]);
    }
    printf("