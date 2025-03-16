#include <stdio.h>

int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    int b[2 * n];
    for (int i = 0; i < 2 * n; i++) {
        b[i] = 1;
    }

    b[0] = b[n - 1] = b[n] = b[2 * n - 1] = 0;

    for (int i = 0; i < m; i++) {
        int r, c;
        scanf("%d %d", &r, &c);
        b[r - 1] = b[n + c - 1] = 0;
    }

    if (n % 2 && b[n / 2] && b[n + n / 2]) {
        b[n / 2] = 0;
    }

    int sum = 0;
    for (int i = 0; i < 2 * n; i++) {
        sum += b[i];
    }

    printf("%d\n", sum);

    return 0;
}
