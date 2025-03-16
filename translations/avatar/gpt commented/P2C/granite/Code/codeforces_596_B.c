
#include <stdio.h>

int main() {
    int n, ans = 0, prev = 0;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        int r;
        scanf("%d", &r);
        ans += abs(r - prev);
        prev = r;
    }
    printf("%d\n", ans);
    return 0;
}
// END-OF-CODE