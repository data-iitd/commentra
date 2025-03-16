#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

// This function calculates a result based on a given string and character.
int cal(char* s, char c) {
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

// This function is responsible for solving the problem by processing the input and outputting the result.
void solve() {
    int n;
    char s[100005];
    scanf("%d", &n);
    scanf("%s", s);
    char sb[100005];
    int j = 0;
    for (int i = 1; i < n; i++) {
        sb[j++] = abs(s[i] - s[i - 1]);
    }
    sb[j] = '\0';
    if (n == 2) {
        printf("%c\n", sb[0]);
        return;
    }
    if (strstr(sb, "1") != NULL) {
        printf("%d\n", cal(sb, '1'));
    } else {
        printf("%d\n", cal(sb, '2') * 2);
    }
}

int main() {
    solve();
    return 0;
}
