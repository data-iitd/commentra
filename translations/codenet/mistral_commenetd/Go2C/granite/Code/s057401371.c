
#include <stdio.h>
#include <string.h>

int main() {
    char s[100];
    fgets(s, sizeof(s), stdin);
    int d = 'a' - 'A';
    for (int i = 0; i < strlen(s); i++) {
        char r = s[i];
        if ('A' <= r && r <= 'Z') {
            r = r + d;
        } else if ('a' <= r && r <= 'z') {
            r = r - d;
        }
        putchar(r);
    }
    printf("\n");
    return 0;
}

// END-OF-CODE