#include <stdio.h>
#include <ctype.h>

int main() {
    char s[100];
    scanf("%s", s);
    int l = strlen(s);
    char ans[3] = "WA";
    if (s[0] != 'A') {
        printf("%s\n", ans);
        return 0;
    }
    int cnt = 0;
    for (int i = 1; i < l; i++) {
        if (isupper(s[i])) {
            if (i == 1 || i == l-1 || s[i] != 'C') {
                printf("%s\n", ans);
                return 0;
            }
            cnt++;
        }
    }
    if (cnt != 1) {
        printf("%s\n", ans);
        return 0;
    }
    ans[0] = 'A';
    ans[1] = 'C';
    ans[2] = '\0';
    printf("%s\n", ans);
    return 0;
}
