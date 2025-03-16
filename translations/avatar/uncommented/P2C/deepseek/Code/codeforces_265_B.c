#include <stdio.h>
#include <stdlib.h>

int main() {
    int n;
    scanf("%d", &n);
    int l[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &l[i]);
    }
    int ans = n - 1;
    int last = 0;
    for (int i = 0; i < n; i++) {
        ans += abs(last - l[i]) + 1;
        last = l[i];
    }
    printf("%d\n", ans);
    return 0;
}
