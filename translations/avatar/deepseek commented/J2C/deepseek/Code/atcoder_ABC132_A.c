#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char s[100];
    scanf("%s", s);

    int len = strlen(s);
    int map[256] = {0};

    for (int i = 0; i < len; i++) {
        map[(unsigned char)s[i]]++;
    }

    int ok = 1;
    for (int i = 0; i < 256; i++) {
        if (map[i] != 2) {
            ok = 0;
            break;
        }
    }

    if (ok && len == 4) {
        printf("Yes\n");
    } else {
        printf("No\n");
    }

    return 0;
}

