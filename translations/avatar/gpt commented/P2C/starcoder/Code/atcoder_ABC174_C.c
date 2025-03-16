#include <stdio.h>
#include <stdlib.h>

int main() {
    int k, t, i;
    scanf("%d", &k);
    t = 0;
    for (i = 1; i <= k; i++) {
        t = (t % k) * 10 + 7;
        if (t % k == 0) {
            printf("%d\n", i);
            break;
        }
    }
    if (i > k) {
        printf("-1\n");
    }
    return 0;
}

