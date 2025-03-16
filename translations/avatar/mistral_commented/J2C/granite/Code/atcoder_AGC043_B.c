

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        int n;
        scanf("%d", &n);
        char s[n];
        scanf("%s", s);
        int ans = 0;
        for (int i = 1; i < n; i++) {
            ans ^= abs(s[i] - s[i - 1]);
        }
        printf("%d\n", ans);
    }
    return 0;
}

