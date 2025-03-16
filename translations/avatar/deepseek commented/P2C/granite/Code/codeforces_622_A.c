

#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);
    int l = 1, r = n;
    while (l < r) {
        int mid = l + (r - l) / 2;
        int idxcnt = mid * (mid + 1) / 2;
        if (idxcnt < n) {
            l = mid + 1;
        } else {
            r = mid;
        }
    }
    l -= 1;
    int idxcnt = l * (l + 1) / 2;
    printf("%d\n", n - idxcnt);
    return 0;
}

