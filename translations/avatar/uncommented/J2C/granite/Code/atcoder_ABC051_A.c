
#include <stdio.h>
#include <string.h>

int main() {
    char a[100];
    fgets(a, 100, stdin);
    printf("%s", strreplace(a, ",", " "));
    return 0;
}

char* strreplace(char* str, const char* from, const char* to) {
    char* tmp = (char*)malloc(strlen(str) + 1);
    strcpy(tmp, str);
    char* cur = tmp;
    while ((cur = strstr(cur, from))!= NULL) {
        memmove(cur + strlen(to), cur + strlen(from), strlen(cur) + 1 - (cur - tmp + strlen(from)));
        memcpy(cur, to, strlen(to));
        cur += strlen(to);
    }
    return tmp;
}

// 