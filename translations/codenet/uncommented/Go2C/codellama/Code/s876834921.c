#include <stdio.h>
#include <string.h>

int main() {
    char s[100];
    scanf("%s", s);
    char *p = strstr(s, "dream");
    while (p != NULL) {
        *p = 'D';
        p = strstr(p + 1, "dream");
    }
    p = strstr(s, "erase");
    while (p != NULL) {
        *p = 'E';
        p = strstr(p + 1, "erase");
    }
    p = strstr(s, "Der");
    while (p != NULL) {
        memmove(p, p + 2, strlen(p + 2) + 1);
        p = strstr(p, "Der");
    }
    p = strstr(s, "Er");
    while (p != NULL) {
        memmove(p, p + 2, strlen(p + 2) + 1);
        p = strstr(p, "Er");
    }
    p = strstr(s, "D");
    while (p != NULL) {
        memmove(p, p + 1, strlen(p + 1) + 1);
        p = strstr(p, "D");
    }
    p = strstr(s, "E");
    while (p != NULL) {
        memmove(p, p + 1, strlen(p + 1) + 1);
        p = strstr(p, "E");
    }
    s[strcspn(s, " \n")] = '\0';

    if (s[0] == '\0') {
        printf("YES\n");
    } else {
        printf("NO\n");
    }

    return 0;
}

