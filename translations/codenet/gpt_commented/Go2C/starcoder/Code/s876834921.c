


#include <stdio.h>
#include <string.h>

int main() {
    char s[1000];
    scanf("%s", s);
    s[strlen(s) - 1] = '\0';
    for (int i = 0; i < strlen(s); i++) {
        if (s[i] == 'D') {
            s[i] = 'd';
        }
        if (s[i] == 'E') {
            s[i] = 'e';
        }
        if (s[i] == 'r') {
            s[i] = 'R';
        }
    }
    if (strcmp(s, "") == 0) {
        printf("YES");
    } else {
        printf("NO");
    }
}

