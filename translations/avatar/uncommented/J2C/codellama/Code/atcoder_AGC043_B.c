
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int cal(char *s, char c) {
    int n = strlen(s);
    int m = n - 1;
    int ans = 0;
    for (int i = 0; i < n; i++) {
        if (s[i] == c && (m & i) == i) {
            ans ^= 1;
        }
    }
    return ans;
}

void solve() {
    int n;
    char s[100000];
    scanf("%d", &n);
    scanf("%s", s);
    if (n == 2) {
        printf("%c\n", s[0]);
        return;
    }
    char *sb = (char *)malloc(sizeof(char) * n);
    for (int i = 1; i < n; i++) {
        sb[i - 1] = abs(s[i] - s[i - 1]);
    }
    s = sb;
    if (strstr(s, "1")) {
        printf("%d\n", cal(s, '1'));
    } else {
        printf("%d\n", cal(s, '2') * 2);
    }
}

int main() {
    solve();
    return 0;
}

