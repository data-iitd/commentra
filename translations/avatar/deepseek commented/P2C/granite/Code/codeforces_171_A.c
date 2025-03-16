
#include <stdio.h>
#include <string.h>

int main() {
    char a[100001], b[100001];
    fgets(a, 100001, stdin);
    fgets(b, 100001, stdin);
    int x = strlen(a) > strlen(b)? strlen(a) : strlen(b);
    char s[100001] = "";
    int c = 0;
    for (int i = 0; i < x; i++) {
        int d = (b[i] - '0') + (a[x - i - 1] - '0') + c;
        if (d > 9) {
            s[i] = (d % 10) + '0';
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
    for (int i = 0; i < x / 2; i++) {
        char temp = s[i];
        s[i] = s[x - i - 1];
        s[x - i - 1] = temp;
    }
    printf("%s\n", s);
    return 0;
}
