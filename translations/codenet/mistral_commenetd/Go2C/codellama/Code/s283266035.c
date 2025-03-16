
#include <stdio.h>

int main() {
    int n, i, ans;
    scanf("%d", &n);
    ans = 0;
    for (i = 1; i*i < n; i++) {
        if (n % i == 0) {
            if (n % (n/i-1) == i) {
                ans += n / i - 1;
            }
        }
    }
    printf("%d\n", ans);
    return 0;
}

