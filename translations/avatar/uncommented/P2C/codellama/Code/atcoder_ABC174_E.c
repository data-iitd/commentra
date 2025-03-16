#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>

int check(int lis[], int k, int mid) {
    int i, k = 0;
    for (i = 0; i < n; i++) {
        if (lis[i] % mid == 0) {
            k++;
        }
        k -= lis[i] / mid;
    }
    return k >= 0;
}

int main() {
    int n, k, i, a, b, mid, ans;
    scanf("%d %d", &n, &k);
    int lis[n];
    for (i = 0; i < n; i++) {
        scanf("%d", &lis[i]);
    }
    a = 1;
    b = lis[n - 1];
    ans = b;
    while (a <= b) {
        mid = (a + b) / 2;
        if (check(lis, k, mid)) {
            ans = mid;
            b = mid - 1;
        } else {
            a = mid + 1;
        }
    }
    printf("%d", ans);
    return 0;
}

