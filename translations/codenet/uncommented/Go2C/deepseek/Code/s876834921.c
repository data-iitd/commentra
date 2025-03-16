#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {
    char s[100001];
    scanf("%s", s);
    int len = strlen(s);

    for (int i = 0; i < len; i++) {
        if (s[i] == 'd' || s[i] == 'D') {
            if (i + 4 < len && (s[i + 1] == 'r' || s[i + 1] == 'R') && (s[i + 2] == 'e' || s[i + 2] == 'E') && (s[i + 3] == 'a' || s[i + 3] == 'A') && (s[i + 4] == 'm' || s[i + 4] == 'M')) {
                i += 4;
                s[i] = '\0';
            } else if (i + 4 < len && (s[i + 1] == 'r' || s[i + 1] == 'R') && (s[i + 2] == 'e' || s[i + 2] == 'E') && (s[i + 3] == 'a' || s[i + 3] == 'A') && (s[i + 4] == 's' || s[i + 4] == 'S')) {
                i += 4;
                s[i] = '\0';
            } else if (i + 4 < len && (s[i + 1] == 'r' || s[i + 1] == 'R') && (s[i + 2] == 'e' || s[i + 2] == 'E') && (s[i + 3] == 's' || s[i + 3] == 'S')) {
                i += 3;
                s[i] = '\0';
            } else if (i + 4 < len && (s[i + 1] == 'r' || s[i + 1] == 'R') && (s[i + 2] == 'e' || s[i + 2] == 'E')) {
                i += 2;
                s[i] = '\0';
            } else if (i + 4 < len && (s[i + 1] == 'e' || s[i + 1] == 'E') && (s[i + 2] == 'a' || s[i + 2] == 'A') && (s[i + 3] == 'm' || s[i + 3] == 'M') && (s[i + 4] == 'e' || s[i + 4] == 'E')) {
                i += 4;
                s[i] = '\0';
            } else if (i + 3 < len && (s[i + 1] == 'e' || s[i + 1] == 'E') && (s[i + 2] == 'a' || s[i + 2] == 'A') && (s[i + 3] == 's' || s[i + 3] == 'S')) {
                i += 3;
                s[i] = '\0';
            } else if (i + 2 < len && (s[i + 1] == 'e' || s[i + 1] == 'E') && (s[i + 2] == 's' || s[i + 2] == 'S')) {
                i += 2;
                s[i] = '\0';
            } else if (i + 1 < len && (s[i + 1] == 'r' || s[i + 1] == 'R')) {
                i += 1;
                s[i] = '\0';
            }
        }
    }

    if (strcmp(s, "") == 0) {
        printf("YES\n");
    } else {
        printf("NO\n");
    }

    return 0;
}
