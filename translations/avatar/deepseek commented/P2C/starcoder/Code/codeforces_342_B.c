
#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, m, s, f, d, i, j, t, l, r, k;
    char c, res[100000];
    scanf("%d %d %d %d", &n, &m, &s, &f);
    if (s < f) {
        d = 1;
        c = 'R';
    } else {
        d = -1;
        c = 'L';
    }
    res[0] = '\0';
    i = 1;
    j = s;
    scanf("%d %d %d", &t, &l, &r);
    k = 1;
    while (j!= f) {
        if (i > t && k < m) {
            scanf("%d %d %d", &t, &l, &r);
            k += 1;
        }
        if (i == t && (l <= j && j <= r || l <= j + d && j + d <= r)) {
            strcat(res, "X");
        } else {
            strcat(res, &c);
        }
        j += d;
        i += 1;
    }
    printf("%s", res);
    return 0;
}

