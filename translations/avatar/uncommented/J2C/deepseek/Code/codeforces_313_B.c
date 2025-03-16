#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    int n;
    scanf("%d", &n);
    char s[n+1];
    scanf("%s", s);
    int cum[n+1];
    cum[0] = cum[n] = 0;
    for (int i = 1; i < n; i++) {
        if (s[i] == s[i-1]) {
            cum[i] = cum[i-1] + 1;
        } else {
            cum[i] = cum[i-1];
        }
    }
    int q;
    scanf("%d", &q);
    while (q--) {
        int l, r;
        scanf("%d %d", &l, &r);
        printf("%d\n", cum[r-1] - cum[l-1]);
    }
    return 0;
}
