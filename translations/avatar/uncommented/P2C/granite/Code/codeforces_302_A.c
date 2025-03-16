
#include <stdio.h>

int main() {
    int n, m, sa, a, b;
    scanf("%d%d", &n, &m);
    sa = 0;
    char s[m];
    for (int i = 0; i < n; i++) {
        char c;
        scanf(" %c", &c);
        sa += c == '-';
    }
    sa = sa < n - sa? sa : n - sa;
    for (int i = 0; i < m; i++) {
        scanf("%d%d", &a, &b);
        b -= a;
        s[i] = b % 2 && b <= sa * 2? '1' : '0';
    }
    s[m] = '\0';
    printf("%s\n", s);
    return 0;
}
//END-OF-CODE