#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>

int main() {
    int n;
    scanf("%d", &n);

    int ans;
    scanf("%d", &ans);

    for (int i = 1; i < n; ++i) {
        int a;
        scanf("%d", &a);
        ans = gcd(ans, a);
    }

    printf("%d\n", ans);

    return 0;
}

