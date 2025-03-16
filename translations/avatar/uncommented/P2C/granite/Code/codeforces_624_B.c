
#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);
    int a[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    int pre = 100000001;
    int ans = 0;
    for (int j = n - 1; j >= 0; j--) {
        ans += (a[j] < pre - 1)? a[j] : pre - 1;
        pre = (a[j] < pre - 1)? a[j] : pre - 1;
    }
    printf("%d\n", ans);
    return 0;
}

