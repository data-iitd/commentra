#include <stdio.h>
#include <ctype.h>
#include <string.h>

int main() {
    char s[100];
    scanf("%s", s);
    int l = strlen(s);
    char ans[] = "AC";

    if (s[0] != 'A') {
        strcpy(ans, "WA");
    }

    int cnt = 0;
    for (int i = 1; i < l; i++) {
        if (isupper(s[i])) {
            if (i == 1 || i == l - 1 || s[i] != 'C') {
                strcpy(ans, "WA");
            }
            cnt++;
        }
    }

    if (cnt != 1) {
        strcpy(ans, "WA");
    }

    printf("%s\n", ans);
    return 0;
}
