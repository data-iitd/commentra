
#include <stdio.h>
#include <string.h>

int main() {
    char s[100];
    fgets(s, sizeof(s), stdin);
    char *p = s;
    while (*p!= '\n') {
        if (*p == 'd' || *p == 'D') {
            if (strstr(p, "dream") == p) {
                p += 5;
                continue;
            }
        } else if (*p == 'e' || *p == 'E') {
            if (strstr(p, "erase") == p) {
                p += 5;
                continue;
            }
        }
        p++;
    }
    *strchr(s, '\n') = '\0';
    if (strlen(s) == 0) {
        printf("YES\n");
    } else {
        printf("NO\n");
    }
    return 0;
}
