#include <stdio.h>
#include <stdlib.h>

int main() {
    int l, r;
    scanf("%d %d", &l, &r);
    int curr = r;
    int s = 0;
    while (curr) {
        s++;
        curr /= 10;
    }
    int first = 10 * s;
    int second = first / 2;
    int ans = -1;
    for (int i = l; i <= r; i++) {
        if (i >= l && i <= r) {
            curr = i;
            char rev[10];
            int index = 0;
            while (curr) {
                rev[index++] = '0' + (9 - (curr % 10));
                curr /= 10;
            }
            rev[index] = '\0';
            int rev_num = atoi(rev);
            int product = rev_num * i;
            if (product > ans) {
                ans = product;
            }
        }
    }
    printf("%d\n", ans);
    return 0;
}
