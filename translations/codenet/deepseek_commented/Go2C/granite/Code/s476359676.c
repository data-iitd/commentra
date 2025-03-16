

#include <stdio.h>
#include <stdlib.h>

int main() {
    int n;
    scanf("%d", &n);

    int ans = 0;
    int aPrev = 0;
    for (int i = 0; i < n; i++) {
        int a;
        scanf("%d", &a);
        switch (1) {
            case a > i || a > aPrev + 1:
                printf("-1\n");
                return 0;
            case a == aPrev + 1:
                ans++;
                break;
            default:
                ans += a;
        }
        aPrev = a;
    }
    printf("%d\n", ans);
}
