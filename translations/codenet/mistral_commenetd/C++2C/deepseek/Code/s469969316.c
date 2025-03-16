#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define rep(i,n) for (int i = 0; i < n; i++)

char input[100], ss[100];
int a[3], it, cnt;

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
    return c == '*' ? And(x, y) : Or(x, y);
}

int main() {
    while (scanf("%s", input) != EOF && strcmp(input, ".")) {
        rep(i,3) a[i] = i;
        cnt = 0;
        rep(i,3) rep(j,3) rep(k,3) {
            a[0] = i; a[1] = j; a[2] = k;
            strcpy(ss, input);
            for (int p = 0; p < strlen(ss); p++) {
                if (ss[p] == 'P') ss[p] = a[0]+'0';
                if (ss[p] == 'Q') ss[p] = a[1]+'0';
                if (ss[p] == 'R') ss[p] = a[2]+'0';
            }
            it = 0;
            if (parse() == 2) cnt++;
        }
        printf("%d\n", cnt);
    }
