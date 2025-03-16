
#include <stdio.h>
#include <string.h>

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

int main() {
    int n;
    scanf("%d", &n);
    char s[n];
    scanf("%s", s);
    int ans = 0;
    for (int i = 1; i < n; i++) {
        ans ^= abs(s[i] - s[i - 1]);
    }
    if (n == 2) {
        printf("%d\n", ans);
        return 0;
    }
    char t[n - 1];
    for (int i = 1; i < n; i++) {
        t[i - 1] = abs(s[i] - s[i - 1]);
    }
    if (strchr(t, '1')) {
        printf("%d\n", cal(t, '1'));
    } else {
        printf("%d\n", cal(t, '2') * 2);
    }
    return 0;
}

