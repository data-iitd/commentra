#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define IN(type) type read##type() { type x; scanf("%" #type, &x); return x; }
#define MOD 1000000007

IN(int)

void main_b() {
    char s[100001];
    scanf("%s", s);

    int pp = 0, na = 0;
    int len = strlen(s);

    for (int i = len - 1; i >= 0; i--) {
        int cc = na + (s[i] - '0');
        na = 0;

        if (cc <= 4) {
            pp += cc;
        } else {
            if (i == 0) {
                pp += 1;
            } else {
                pp += 10 - cc;
            }
        }
    }

    printf("%d\n", pp);
}

int main() {
    char s[100001];
    scanf("%s", s);

    int pmin = 1000, mmin = 0;
    int len = strlen(s);
    char temp[len + 2];
    temp[0] = '0';
    strcpy(temp + 1, s);

    for (int i = len; i >= 0; i--) {
        int v = temp[i] - '0';
        int npmin = (pmin + 10 - (v + 1) < mmin + 10 - v) ? pmin + 10 - (v + 1) : mmin + 10 - v;
        int nmmin = (pmin + v + 1 < mmin + v) ? pmin + v + 1 : mmin + v;

        pmin = npmin;
        mmin = nmmin;
    }

    printf("%d\n", (pmin < mmin) ? pmin : mmin);

    return 0;
}
