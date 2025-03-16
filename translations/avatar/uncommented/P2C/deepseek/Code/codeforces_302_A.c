#include <stdio.h>
#include <string.h>

int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    char s[n+1];
    scanf("%s", s);

    int sa = 0;
    for (int i = 0; i < n; i++) {
        if (s[i] == '-') {
            sa++;
        }
    }

    sa = sa < n - sa ? sa : n - sa;

    char ss[m][2];
    for (int i = 0; i < m; i++) {
        int a, b;
        scanf("%d %d", &a, &b);
        b -= a;
        if (b % 2 == 1 && b <= 2 * sa) {
            strcpy(ss[i], "1\n");
        } else {
            strcpy(ss[i], "0\n");
        }
    }

    for (int i = 0; i < m; i++) {
        printf("%s", ss[i]);
    }

    return 0;
}
