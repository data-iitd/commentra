
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char s[1000000];
    scanf("%s", s);
    int pp = 0, na = 0;
    for (int i = strlen(s) - 1; i >= 0; i--) {
        int cc = na + s[i] - '0';
        na = 0;
        if (cc <= 4) {
            pp += cc;
        } else {
            na = 1;
            if (i == 0) {
                pp += 1;
            }
            pp += 10 - cc;
        }
    }
    printf("%d\n", pp);
    return 0;
}

