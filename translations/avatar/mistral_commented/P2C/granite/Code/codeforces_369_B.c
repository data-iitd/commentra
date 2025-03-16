

#include <stdio.h>

int main() {
    int n, k, l, r, sa, sk;
    scanf("%d %d %d %d %d %d", &n, &k, &l, &r, &sa, &sk);
    int ans[n];
    for (int i = 0; i < k; i++) {
        ans[i] = sa / k + 1;
    }
    for (int i = k; i < n; i++) {
        ans[i] = sa / k;
    }
    for (int i = 0; i < sk; i++) {
        ans[i] += 1;
    }
    for (int i = 0; i < n; i++) {
        printf("%d ", ans[i]);
    }
    printf("\n");
    return 0;
}

Translate the above Python code to Java and end with comment "