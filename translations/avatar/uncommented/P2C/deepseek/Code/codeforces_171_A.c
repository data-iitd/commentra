#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main() {
    char a[1001], b[1001];
    int x, i, d, c = 0;
    char s[1002] = {0};

    scanf("%s %s", a, b);

    x = strlen(a) > strlen(b) ? strlen(a) : strlen(b);

    for (i = 0; i < x; i++) {
        if (i < strlen(a)) {
            a[i] = a[i] == '\0' ? '0' : a[i];
        } else {
            a[i] = '0';
        }
        if (i < strlen(b)) {
            b[i] = b[i] == '\0' ? '0' : b[i];
        } else {
            b[i] = '0';
        }
    }

    for (i = 0; i < x; i++) {
        d = (a[x - i - 1] - '0') + (b[x - i - 1] - '0') + c;
        if (d > 9) {
            s[i] = d - 10 + '0';
            c = 1;
        } else {
            s[i] = d + '0';
            c = 0;
        }
    }

    if (c == 1) {
        s[x] = '1';
        x++;
    }

    for (i = 0; i < x; i++) {
        printf("%c", s[x - i - 1]);
    }
    printf("\n");

    return 0;
}
