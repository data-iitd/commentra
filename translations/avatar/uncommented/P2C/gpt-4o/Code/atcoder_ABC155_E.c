#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MOD 1000000007

int main_b() {
    char s[1001];
    scanf("%s", s);
    long long pp = 0;
    int na = 0;
    int len = strlen(s);
    
    for (int i = len - 1; i >= 0; i--) {
        int c = s[i] - '0';
        int cc = na + c;
        na = 0;
        if (cc <= 4) {
            pp += cc;
        } else {
            na = 1;
            if (i == len - 1) {
                pp += 1;
            }
            pp += 10 - cc;
        }
    }
    printf("%lld\n", pp);
    return 0;
}

long long main_func() {
    char s[1001];
    scanf("%s", s);
    long long pmin = 1000;
    long long mmin = 0;
    int len = strlen(s);
    char new_s[1002];
    new_s[0] = '0';
    strcpy(new_s + 1, s);
    
    for (int i = len; i >= 0; i--) {
        int v = new_s[i] - '0';
        long long npmin = (pmin + 10 - (v + 1) < mmin + 10 - v) ? (pmin + 10 - (v + 1)) : (mmin + 10 - v);
        long long nmmin = (pmin + v + 1 < mmin + v) ? (pmin + v + 1) : (mmin + v);
        pmin = npmin;
        mmin = nmmin;
    }
    return (pmin < mmin) ? pmin : mmin;
}

int main() {
    long long ret = main_func();
    printf("%lld\n", ret);
    return 0;
}

// <END-OF-CODE>
