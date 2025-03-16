#include <stdio.h>
#include <stdlib.h>

#define MAX_INPUT_SIZE 1000000001

int main() {
    int n;
    scanf("%d", &n);

    int ans = 0;
    int aPrev = 0;
    for (int i = 0; i < n; i++) {
        int a;
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

