
#include <stdio.h>

int main() {
    int n, m, s, f;
    scanf("%d %d %d %d", &n, &m, &s, &f);
    char c = (s < f)? 'R' : 'L';
    int d = (s < f)? 1 : -1;
    char res[100000];
    int i = 1, j = s, k = 1;
    int t, l, r;
    while (j!= f) {
        if (i > n && k < m) {
            scanf("%d %d %d", &t, &l, &r);
            k++;
        }
        if (i == t && (l <= j && j <= r || l <= j + d && j + d <= r)) {
            res[i - 1] = 'X';
        } else {
            res[i - 1] = c;
            j += d;
        }
        i++;
    }
    res[i - 1] = '\0';
    printf("%s\n", res);
    return 0;
}
//END-OF-CODE