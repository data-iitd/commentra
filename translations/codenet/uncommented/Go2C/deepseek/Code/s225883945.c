#include <stdio.h>
#include <stdlib.h>

int nextInt() {
    int value;
    scanf("%d", &value);
    return value;
}

int main() {
    int n = nextInt();
    int k = nextInt();
    int a[n];
    for (int i = 0; i < n; i++) {
        a[i] = nextInt();
    }
    // 変数未使用エラー回避
    a[0] = 0;

    int sum = k;
    int ans = 1;
    while (sum < n) {
        sum = sum - 1 + k;
        ans++;
    }
    printf("%d\n", ans);
    return 0;
}
