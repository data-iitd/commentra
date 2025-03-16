#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, d;
    scanf("%d %d", &n, &d);

    int x[n];
    int m = 0, q = 0;

    for (int i = 0; i < n; i++) {
        scanf("%d", &x[i]);
    }

    for (int i = 0; i < n - 1; i++) {
        if (x[i] >= x[i + 1]) {
            q = (x[i] - x[i + 1]) / d + 1;
            m += q;
            x[i + 1] += q * d;
        }
    }

    printf("%d\n", m);

    return 0;
}
