#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>
#include <assert.h>
#include <limits.h>
#include <ctype.h>

int main() {
    int n;
    scanf("%d", &n);
    if (n == 1) {
        printf("0");
        return 0;
    }
    int ans = 0;
    int f = 2;
    while (f * f <= n) {
        if (n % f == 0) {
            ans += f;
            n /= f;
        } else {
            f += 1;
        }
    }
    if (n!= 1) {
        ans += n;
    }
    printf("%d", ans);
    return 0;
}

