
#include <stdio.h>
#include <stdlib.h>
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
    char s[100000];
    scanf("%s", s);
    char *sb = (char *)malloc(sizeof(char) * n);
    for (int i = 1; i < n; i++) {
        sb[i] = abs(s[i] - s[i - 1]);
    }
    if (n == 2) {
        printf("%c", sb[0]);
        return 0;
    }
    s = sb;
    if (strstr(s, "1")) {
        printf("%d", cal(s, '1'));
    } else {
        printf("%d", cal(s, '2') * 2);
    }
    return 0;
}

