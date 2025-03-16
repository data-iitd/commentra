#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    int n;
    scanf("%d", &n);
    char s[n][n];
    for (int i = 0; i < n; i++) {
        scanf("%s", s[i]);
    }
    int flag = 0;
    int d1[n], d2[n];
    int rem[256] = {0};
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i == j) {
                d1[i] = s[i][j];
            }
            if (i == n - j - 1) {
                d2[i] = s[i][j];
            }
            if (i != j && i != n - j - 1) {
                rem[(int)s[i][j]]++;
            }
        }
    }
    if (rem[(int)'a'] != 1 && rem[(int)'b'] != 1 && rem[(int)'c'] != 1 && rem[(int)'d'] != 1 && rem[(int)'e'] != 1 && rem[(int)'f'] != 1 && rem[(int)'g'] != 1 && rem[(int)'h'] != 1 && rem[(int)'i'] != 1 && rem[(int)'j'] != 1 && rem[(int)'k'] != 1 && rem[(int)'l'] != 1 && rem[(int)'m'] != 1 && rem[(int)'n'] != 1 && rem[(int)'o'] != 1 && rem[(int)'p'] != 1 && rem[(int)'q'] != 1 && rem[(int)'r'] != 1 && rem[(int)'s'] != 1 && rem[(int)'t'] != 1 && rem[(int)'u'] != 1 && rem[(int)'v'] != 1 && rem[(int)'w'] != 1 && rem[(int)'x'] != 1 && rem[(int)'y'] != 1 && rem[(int)'z'] != 1) {
        printf("NO\n");
    } else if (memcmp(d1, d2, n * sizeof(int)) != 0) {
        printf("NO\n");
    } else if (rem[(int)d1[0]] != n) {
        printf("NO\n");
    } else if (rem[(int)d1[0]] == rem[(int)d1[0]]) {
        printf("NO\n");
    } else {
        printf("YES\n");
    }
    return 0;
}
