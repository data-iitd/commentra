
#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, k;
    scanf("%d %d", &n, &k);

    int a[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    int sum = k;
    int ans = 1;
    while (sum < n) {
        sum = sum - 1 + k;
        ans++;
    }

    printf("%d\n", ans);

    return 0;
}
