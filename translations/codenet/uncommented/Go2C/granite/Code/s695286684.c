
#include <stdio.h>
#include <string.h>

int main() {
    char s[100];
    scanf("%s", s);
    printf("%s\n", str_replace(s, "2017", "2018"));
    return 0;
}

char *str_replace(char *s, char *old, char *new) {
    char *p = s;
    while (*p!= '\0') {
        if (strstr(p, old) == p) {
            char *q = p + strlen(old);
            while (*q!= '\0') {
                *p++ = *q++;
            }
            while (*old!= '\0') {
                *p++ = *old++;
            }
            *p = '\0';
        }
        p++;
    }
    return s;
}

