#include <stdio.h>
#include <stdlib.h>

int main() {
    int i, n, ans;
    scanf("%d", &n);
    int *p = (int *)malloc(n * sizeof(int));
    for (i = 0; i < n; i++) {
        scanf("%d", &p[i]);
    }
    ans = 0;
    for (i = 0; i < n - 1; i++) {
        if (p[i] == i + 1) {
            p[i + 1] = p[i];
            ans += 1;
        }
    }
    if (p[n - 1] == n) {
        ans += 1;
    }
    printf("%d\n", ans);
    free(p);
    return 0;
}
