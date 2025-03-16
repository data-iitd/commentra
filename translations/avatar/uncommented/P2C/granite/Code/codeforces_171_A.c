
#include <stdio.h>
#include <string.h>

int main() {
    char a[100001], b[100001];
    fgets(a, 100001, stdin);
    fgets(b, 100001, stdin);
    int x = strlen(a) > strlen(b)? strlen(a) : strlen(b);
    a[strlen(a) - 1] = '\0';
    b[strlen(b) - 1] = '\0';
    char c[x + 1];
    memset(c, 0, sizeof(c));
    int carry = 0;
    for (int i = 0; i < x; i++) {
        int d = (b[x - i - 1] - '0') + (a[strlen(a) - i - 1] - '0') + carry;
        c[x - i - 1] = d % 10 + '0';
        carry = d / 10;
    }
    if (carry > 0) {
        c[0] = carry + '0';
    }
    printf("%s\n", c);
    return 0;
}
//END-OF-CODE