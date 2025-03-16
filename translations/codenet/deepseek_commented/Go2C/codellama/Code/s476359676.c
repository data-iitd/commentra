
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    int n, i, a, aPrev, ans;
    scanf("%d", &n);
    ans = 0;
    aPrev = 0;
    for (i = 0; i < n; i++) {
        scanf("%d", &a);
        if (a > i || a > aPrev + 1) {
            printf("-1\n");
            return 0;
        }
        if (a == aPrev + 1) {
            ans++;
        } else {
            ans += a;
        }
        aPrev = a;
    }
    printf("%d\n", ans);
    return 0;
}

