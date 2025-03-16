#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main() {
    char input[100000];
    while (scanf("%s", input)!= EOF && strcmp(input, ".")) {
        int a[3] = {0, 1, 2};
        int cnt = 0;
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                for (int k = 0; k < 3; k++) {
                    a[0] = i; a[1] = j; a[2] = k;
                    char *ss = strdup(input);
                    for (char *c = ss; *c; c++) {
                        if (*c == 'P') *c = a[0]+'0';
                        if (*c == 'Q') *c = a[1]+'0';
                        if (*c == 'R') *c = a[2]+'0';
                    }
                    int it = 0;
                    if (parse(ss) == 2) cnt++;
                }
            }
        }
        printf("%d\n", cnt);
    }
}

int parse(char *ss) {
    char c = ss[it++];
    if ('0' <= c && c <= '2') return c-'0';
    if (c == '-') return Not(parse(ss));

    int x = parse(ss);
    c = ss[it++];
    int y = parse(ss);
    ++it;
    return c == '*'? And(x, y) : Or(x, y);
}

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

