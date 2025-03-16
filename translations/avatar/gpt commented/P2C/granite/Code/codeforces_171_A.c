
#include <stdio.h>
#include <string.h>

int main() {
    char a[100001], b[100001];
    fgets(a, 100001, stdin);
    fgets(b, 100001, stdin);
    int x = strlen(a) > strlen(b)? strlen(a) : strlen(b);
    a[strlen(a) - 1] = '\0';
    b[strlen(b) - 1] = '\0';
    char s[100001] = "";
    int c = 0;
    for (int i = 0; i < x; i++) {
        int d = b[i] - '0' + a[x - i - 1] - '0' + c;
        if (d > 9) {
            s[strlen(s)] = d % 10 + '0';
            c = 1;
        } else {
            s[strlen(s)] = d + '0';
            c = 0;
        }
    }
    if (c == 1) {
        s[strlen(s)] = '1';
    }
    printf("%s\n", s);
    return 0;
}
