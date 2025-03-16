

#include <stdio.h>

int main() {
    int n, ans = 0;
    scanf("%d", &n);
    for (int i = 1; i * i < n; i++) {
        if (n % i == 0) {
            if (n % (n / i - 1) == i) {
                ans += n / i - 1;
            }
        }
    }
    printf("%d\n", ans);
    return 0;
}

