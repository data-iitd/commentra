#include <stdio.h>

int main() {
    int n, m, s, f;
    scanf("%d %d %d %d", &n, &m, &s, &f);

    int d = (s < f) ? 1 : -1;
    char c = (d == 1) ? 'R' : 'L';
    char res[1000] = "";  // Assuming the maximum path length is 1000
    int i = 1, j = s;

    int t, l, r;
    int k = 1;

    while (j != f) {
        if (i > t && k < m) {
            scanf("%d %d %d", &t, &l, &r);
            k++;
        }

        if (i == t && (l <= j && j <= r || l <= j + d && j + d <= r)) {
            sprintf(res, "%sX", res);
        } else {
            sprintf(res, "%s%c", res, c);
            j += d;
        }

        i++;
    }

    printf("%s\n", res);

    return 0;
}
