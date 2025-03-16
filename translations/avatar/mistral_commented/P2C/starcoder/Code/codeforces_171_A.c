#include <stdio.h>
#include <string.h>

int main() {
    char a[100], b[100];
    scanf("%s %s", a, b);
    int x = strlen(a) > strlen(b)? strlen(a) : strlen(b);
    int c = 0;
    char s[100];
    for (int i = 0; i < x; i++) {
        int d = (int)b[i] + (int)a[x-i-1] + c;
        if (d > 9) {
            s[i] = d%10 + '0';
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
    printf("%d", atoi(s));
    return 0;
}

