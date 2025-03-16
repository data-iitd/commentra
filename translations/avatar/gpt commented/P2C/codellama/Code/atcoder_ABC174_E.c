#include <stdio.h>
#include <stdlib.h>

int check(int lis[], int k, int mid) {
    int i;
    for (i = 0; i < sizeof(lis) / sizeof(int); i++) {
        if (lis[i] % mid == 0) {
            k++;
        }
        k -= lis[i] / mid;
    }
    return k >= 0;
}

int main() {
    int n, k, i;
    scanf("%d %d", &n, &k);
    int lis[n];
    for (i = 0; i < n; i++) {
        scanf("%d", &lis[i]);
    }
    int a = 1, b = lis[n - 1];
    int ans = b;
    while (a <= b) {
        int mid = (a + b) / 2;
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
