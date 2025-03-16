#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int cal(const char *s, char c) {
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
    scanf("%d", &n);
    char s[100001]; // Assuming the maximum length of the string is 100000
    scanf("%s", s);
    
    char sb[100001]; // To store the absolute differences
    int sb_index = 0;

    for (int i = 1; i < n; i++) {
        sb[sb_index++] = abs(s[i] - s[i - 1]) + '0'; // Convert to char
    }
    sb[sb_index] = '\0'; // Null-terminate the string

    if (n == 2) {
        printf("%c\n", sb[0]);
        return;
    }

    if (strchr(sb, '1')) {
        printf("%d\n", cal(sb, '1'));
    } else {
        printf("%d\n", cal(sb, '2') * 2);
    }
}

int main() {
    solve();
    return 0;
}
