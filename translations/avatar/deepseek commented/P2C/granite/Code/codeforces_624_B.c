
#include <stdio.h>
#include <algorithm>

int main() {
    int n;
    scanf("%d", &n);
    int a[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    std::sort(a, a + n, std::greater<int>());
    int pre = 100000001;
    int ans = 0;
    for (int j = 0; j < n; j++) {
        ans += std::max(0, std::min(pre - 1, a[j]));
        pre = std::max(0, std::min(pre - 1, a[j]));
    }
    printf("%d\n", ans);
    return 0;
}
