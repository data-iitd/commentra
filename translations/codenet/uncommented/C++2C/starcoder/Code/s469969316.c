#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int a[3], it, cnt;
char input[100000], ss[100000];

int Not(int x) {
    return 2-x;
}

int And(int x, int y) {
    if (x*y == 0) return 0;
    if (x == 2 && y == 2) return 2;
    return 1;
}

int Or(int x, int y) {
    if (x == 2 || y == 2) return 2;
    if (x == 1 || y == 1) return 1;
    return 0;
}

int parse() {
    char c = ss[it++];
    if ('0' <= c && c <= '2') return c-'0';
    if (c == '-') return Not(parse());

    int x = parse();
    c = ss[it++];
    int y = parse();
    ++it;
    return c == '*'? And(x, y) : Or(x, y);
}

int main() {
    while (fgets(input, 100000, stdin) && input[0]!= '.') {
        cnt = 0;
        rep (i,3) rep (j,3) rep (k,3) {
            a[0] = i; a[1] = j; a[2] = k;
            strcpy(ss, input);
            for (int i = 0; ss[i]; i++) {
                if (ss[i] == 'P') ss[i] = a[0]+'0';
                if (ss[i] == 'Q') ss[i] = a[1]+'0';
                if (ss[i] == 'R') ss[i] = a[2]+'0';
            }
            it = 0;
            if (parse() == 2) cnt++;
        }
        printf("%d\n", cnt);
    }
}

