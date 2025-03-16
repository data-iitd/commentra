#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>
#include <limits.h>
#include <float.h>
#include <ctype.h>
#include <assert.h>

int main() {
    int t;
    scanf("%d", &t);
    while (t-- > 0) {
        long n, a, b;
        scanf("%ld %ld %ld", &n, &a, &b);
        if (n < a) {
            printf("No\n");
            continue;
        }
        if (a == b) {
            if (n % a == 0) {
                printf("Yes\n");
            } else {
                printf("No\n");
            }
            continue;
        }
        long x = b / (b - a);
        if (n > x * a) {
            printf("Yes\n");
            continue;
        }
        long low = 1;
        long high = x + 1;
        long ans = 1;
        while (low <= high) {
            long mid = (low + high) / 2;
            if (mid * a < n) {
                low = mid + 1;
            } else {
                ans = mid;
                high = mid - 1;
            }
        }
        if (n > (ans - 1) * b && n < ans * a) {
            printf("No\n");
        } else {
            printf("Yes\n");
        }
    }
    return 0;
}
