
#include <stdio.h>

int main() {
    int n, m, a, b, sa = 0;
    scanf("%d%d", &n, &m);
    char s[n];
    scanf("%s", s);
    for (int i = 0; i < n; i++) {
        sa += s[i] == '-';
    }
    sa = sa < n - sa? sa : n - sa;
    char *ss = malloc(m * 2);
    for (int i = 0; i < m; i++) {
        scanf("%d%d", &a, &b);
        b -= a;
        ss[i * 2] = b % 2 && b <= sa * 2? '1' : '0';
        ss[i * 2 + 1] = '\n';
    }
    printf("%s", ss);
    free(ss);
    return 0;
}
