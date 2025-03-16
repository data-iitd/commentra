
#include <stdio.h>
#include <string.h>

int main() {
    char s[100001];
    scanf("%s", s);
    char d[100001];
    int len = 0;
    for (int i = 0; s[i]!= '\0'; i++) {
        if (s[i] == '0') {
            d[len++] = '0';
        } else if (s[i] == '1') {
            d[len++] = '1';
        } else if (s[i] == 'B' && len > 0) {
            len--;
        }
    }
    d[len] = '\0';
    printf("%s\n", d);
    return 0;
}
//END-OF-CODE