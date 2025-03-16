
#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    int c[n];
    for (int i = 0; i < n; i++) {
        char s[m];
        scanf("%s", s);
        int g = -1, s_ = -1;
        for (int j = 0; j < m; j++) {
            if (s[j] == 'G') g = j;
            if (s[j] == 'S') s_ = j;
        }
        c[i] = s_ - g;
    }
    int min = c[0];
    for (int i = 1; i < n; i++) {
        if (c[i] < min) min = c[i];
    }
    if (min < 0) printf("-1\n");
    else printf("%d\n", min);
    return 0;
}
// END-OF-CODE