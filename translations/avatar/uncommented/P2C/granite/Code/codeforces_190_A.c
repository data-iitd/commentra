
#include <stdio.h>

int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    if (n < 1) {
        if (m < 1) {
            printf("%d %d\n", n, m);
            return 0;
        }
        printf("Impossible\n");
        return 0;
    }
    if (m > n) {
        int min = m;
        int max = n + m - 1;
        printf("%d %d\n", min, max);
    }
    if (m <= n) {
        int min = n;
        int max = n + m - 1;
        if (m == 0) {
            max = n;
        }
        printf("%d %d\n", min, max);
    }
    return 0;
}
