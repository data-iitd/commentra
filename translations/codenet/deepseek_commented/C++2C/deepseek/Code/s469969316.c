#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define rep(i,n) for (int i = 0; i < int(n); i++)

char input[100], ss[100];
int a[3], it, cnt;

// Step 1: Define the Not function
int Not(int x) {
    return 2-x;
}

// Step 2: Define the And function
int And(int x, int y) {
    if (x*y == 0) return 0;
    if (x == 2 && y == 2) return 2;
    return 1;
}

// Step 3: Define the Or function
int Or(int x, int y) {
    if (x == 2 || y == 2) return 2;
    if (x == 1 || y == 1) return 1;
    return 0;
}

// Step 4: Implement the parse function
int parse() {
    char c = ss[it++];
    if ('0' <= c && c <= '2') return c-'0';
    if (c == '-') return Not(parse());

    int x = parse();
    c = ss[it++];
    int y = parse();
    it++;
    return c == '*' ? And(x, y) : Or(x, y);
}

// Step 5: Implement the main function
int main() {
    while (scanf("%s", input) != EOF && strcmp(input, ".") != 0) {
        rep (i,3) a[i] = i;
        cnt = 0;
        rep (i,3) rep (j,3) rep (k,3) {
            a[0] = i; a[1] = j; a[2] = k;
            strcpy(ss, input);
            for (int i = 0; ss[i] != '\0'; i++) {
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

// Step 6: Output the count
