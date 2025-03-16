#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define IN(type) type IN() { type x; scanf("%d", &x); return x; }
#define mod 1000000007

int main() {
    char s[100001];
    int pp = 0, na = 0;
    scanf("%s", s);

    for (int i = strlen(s) - 1; i >= 0; i--) {
        int cc = na + (s[i] - '0');
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

