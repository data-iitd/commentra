#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

bool check(int n, int wei, int* book, int book_size) {
    int tmp = wei;
    n--;
    for (int i = 0; i < book_size; i++) {
        if (tmp < book[i]) {
            if (n > 0) {
                n--;
                tmp = wei;
                if (tmp < book[i])
                    return false;
            } else {
                return false;
            }
        }
        tmp -= book[i];
    }
    return true;
}

int main() {
    int m, n;
    while (scanf("%d %d", &m, &n) == 2 && m != 0) {
        int book[n];
        for (int i = 0; i < n; i++) {
            scanf("%d", &book[i]);
        }

        int l = 0;
        int r = 1500000;
        int ans;
        while (l < r) {
            int mid = (l + r) / 2;
            if (check(m, mid, book, n)) {
                ans = mid;
                r = mid;
            } else {
                l = mid;
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}
