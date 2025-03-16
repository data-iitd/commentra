#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char s[1000];
    scanf("%s", s);
    int len = strlen(s);
    int dt[256] = {0};
    for (int i = 0; i < len; i++) {
        dt[(unsigned char)s[i]]++;
    }
    int cnt = 0;
    int x = 1;
    for (int i = 0; i < 256; i++) {
        if (dt[i] % 2 != 0) {
            if (cnt < 1) {
                cnt++;
            } else {
                x = 0;
                break;
            }
        }
    }
    if (x) {
        printf("First\n");
    } else if (!x && len % 2 == 0) {
        printf("Second\n");
    } else if (!x && len % 2 != 0) {
        printf("First\n");
    }
    return 0;
}
