#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, x;
    scanf("%d %d", &n, &x);
    int a[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    int b[n][n];
    for (int i = 0; i < n; i++) {
        int m = a[i];
        for (int j = 0; j < n; j++) {
            int k = (i - j + n) % n;
            m = (m < a[k]) ? m : a[k];
            b[j][i] = m;
        }
    }

    int m = 1000000000000000;
    for (int i = 0; i < n; i++) {
        int sum = 0;
        for (int j = 0; j < n; j++) {
            sum += b[i][j];
        }
        int current = sum + x * i;
        m = (m < current) ? m : current;
    }

    printf("%d\n", m);
    return 0;
}
