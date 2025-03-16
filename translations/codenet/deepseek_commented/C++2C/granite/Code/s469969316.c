
#include <stdio.h>
#include <string.h>

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
    char input[1024];
    while (scanf("%s", input)!= EOF && input[0]!= '.') {
        int a[3] = {0, 1, 2};
        int cnt = 0;
        do {
            char ss[1024];
            strcpy(ss, input);
            for (int i = 0; i < 3; i++) {
                for (int j = 0; j < strlen(ss); j++) {
                    if (ss[j] == 'P') ss[j] = a[0]+'0';
                    if (ss[j] == 'Q') ss[j] = a[1]+'0';
                    if (ss[j] == 'R') ss[j] = a[2]+'0';
                }
            }
            int it = 0;
            if (parse() == 2) cnt++;
        } while (next_permutation(a, a+3));
        printf("%d\n", cnt);
    }
}

// Step 6: Output the count