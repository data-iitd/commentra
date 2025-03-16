#include <stdio.h>

int main() {
    int n, m, s, f;
    scanf("%d %d %d %d", &n, &m, &s, &f);
    int d = (s < f) ? 1 : -1;
    char c = (s < f) ? 'R' : 'L';
    char res[100000]; // Assuming the maximum length of the result string
    int i = 1;
    int j = s;
    int t, l, r;
    int k = 1;

    while (j != f) {
        if (i > t && k < m) {
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

    res[i - 1] = '\0'; // Null-terminate the string
    printf("%s\n", res);

    return 0;
}
