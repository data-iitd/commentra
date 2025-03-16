
#include <stdio.h>
#include <stdlib.h>

int main() {
    int k, t = 0;
    scanf("%d", &k);
    for (int i = 1; i <= k; i++) {
        t = (t % k) * 10 + 7;
        if (t % k == 0) {
            printf("%d\n", i);
            return 0;
        }
    }
    printf("-1\n");
    return 0;
}
// END-OF-CODE