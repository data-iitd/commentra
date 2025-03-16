#include <stdio.h>
#include <limits.h>

int main() {
    int k, t = 0, i;
    scanf("%d", &k);
    for (i = 1; i <= k; i++) {
        t = (t % k) * 10 + 7;
        if (t % k == 0) {
            printf("%d\n", i);
            return 0;
        }
    }
    printf("-1\n");
    return 0;
}
