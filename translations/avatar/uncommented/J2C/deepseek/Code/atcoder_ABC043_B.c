#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char s[100001];
    scanf("%s", s);
    char d[100001];
    int d_len = 0;

    for (int i = 0; i < strlen(s); i++) {
        if (s[i] == '0') {
            d[d_len++] = '0';
        } else if (s[i] == '1') {
            d[d_len++] = '1';
        } else if (s[i] == 'B' && d_len > 0) {
            d_len--;
        }
    }
    d[d_len] = '\0';
    printf("%s\n", d);
    return 0;
}
