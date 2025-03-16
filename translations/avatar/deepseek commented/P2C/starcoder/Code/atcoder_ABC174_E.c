#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, k;
    scanf("%d %d", &n, &k);
    int lis[n];
    for (int i = 0; i < n; i++) {
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
    printf("%d\n", ans);
    return 0;
}

int check(int lis[], int k, int mid) {
    for (int i = 0; i < n; i++) {
        if (lis[i] % mid == 0) {
            k++;
        }
        k -= lis[i] / mid;
    }
    return k >= 0;
}

