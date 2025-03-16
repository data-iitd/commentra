
#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, m, s, f, t, l, r, k, i, j, d;
    char c;
    char *res;

    scanf("%d %d %d %d", &n, &m, &s, &f);

    if (s < f) {
        d = 1;
        c = 'R';
    } else {
        d = -1;
        c = 'L';
    }

    res = (char *)malloc(sizeof(char) * (n + 1));
    i = 1;
    j = s;
    t = l = r = k = 0;

    while (j != f) {
        if (i > t && k < m) {
            scanf("%d %d %d", &t, &l, &r);
            k++;
        }

        if (i == t && (l <= j <= r || l <= j + d <= r)) {
            res[i - 1] = 'X';
        } else {
            res[i - 1] = c;
            j += d;
        }

        i++;
    }

    printf("%s", res);
    free(res);

    return 0;
}

