
#include <stdio.h>
#include <string.h>

int main() {
    char s[100];
    // Read a string from the standard input and store it in the variable's'.
    scanf("%s", s);
    // Replace all occurrences of "2017" with "2018" in the string's' and print the result.
    printf("%s\n", str_replace("2017", "2018", s));
    return 0;
}

char* str_replace(const char* old, const char* new, const char* str) {
    char* result = (char*)malloc(strlen(str) + 1);
    char* p = result;
    const char* q = str;
    while (*q) {
        if (strstr(q, old) == q) {
            q += strlen(old);
            p = stpcpy(p, new);
        } else {
            *p++ = *q++;
        }
    }
    *p = '\0';
    return result;
}

