#include <stdio.h>

int main() {
    int n, l = 1, r, mid;
    scanf("%d", &n);
    r = n;
    while (l < r) {
        mid = l + (r - l) / 2;
        double idxcnt = mid * (mid + 1) / 2;
        if (idxcnt < n) {
            l = mid + 1;
        } else {
            r = mid;
        }
    }
    l -= 1;
    double idxcnt = l * (l + 1) / 2;
    printf("%d\n", (int)(n - idxcnt));
    return 0;
}
