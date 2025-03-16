#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>
#include <assert.h>

int main() {
    int n;
    scanf("%d", &n);
    int ans = 0;
    int i;
    for (i = 1; i <= n; i++) {
        ans += i;
    }
    printf("%d", ans);
    return 0;
}

