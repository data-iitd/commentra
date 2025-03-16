
#include <stdio.h>
#include <string.h>

int main() {
    char s[1000];
    scanf("%s", s);
    s = str_replace(s, "dream", "D", -1);
    s = str_replace(s, "erase", "E", -1);
    s = str_replace(s, "Der", "", -1);
    s = str_replace(s, "Er", "", -1);
    s = trim(s);
    if (s == "") {
        printf("YES");
    } else {
        printf("NO");
    }
    return 0;
}

char* str_replace(char* s, char* old, char* new, int count) {
    char* p = s;
    while (p = strstr(p, old)) {
        memmove(p + strlen(new), p + strlen(old), strlen(p) + 1);
        memcpy(p, new, strlen(new));
        p += strlen(new);
    }
    return s;
}

char* trim(char* s) {
    char* p = s;
    while (*p =='') {
        p++;
    }
    if (*p == '\0') {
        return s;
    }
    char* q = p + strlen(p) - 1;
    while (*q =='') {
        *q = '\0';
        q--;
    }
    return s;
}

