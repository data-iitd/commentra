
#include <stdio.h>

int main() {
    int n, k;
    scanf("%d %d", &n, &k);
    char v[n];
    scanf("%s", v);

    char d[2][10] = { "LEFT", "RIGHT" };
    int f = k - 1 < n - k;
    int m = k - 1 < n - k? k - 1 : n - k;

    for (int i = 0; i < m; i++) {
        printf("%s\n", d[!f]);
    }
    for (int i = n - 1; i >= 0; i--) {
        printf("PRINT %c\n", v[i]);
        printf("%s\n", d[f]);
    }

    return 0;
}
// END-OF-CODE