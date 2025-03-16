#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    int *b = (int *)malloc(n * 2 * sizeof(int));
    for (int i = 0; i < n * 2; i++) {
        b[i] = 1;
    }
    b[0] = b[n - 1] = b[n] = b[2 * n - 1] = 0;
    for (int i = 0; i < m; i++) {
        int r, c;
        scanf("%d %d", &r, &c);
        b[r - 1] = b[n + c - 1] = 0;
    }
    if (n % 2 == 1 && b[n / 2] == 1 && b[n + n / 2] == 1) {
        b[n / 2] = 0;
    }
    int sum = 0;
    for (int i = 0; i < n * 2; i++) {
        sum += b[i];
    }
    printf("%d\n", sum);
    free(b);
    return 0;
}
