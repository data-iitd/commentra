
#include <stdio.h>

int main() {
    int n, d;
    scanf("%d %d", &n, &d);
    int x[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &x[i]);
    }
    int m = 0, q = 0;
    for (int a = 0; a < n - 1; a++) {
        if (x[a] >= x[a + 1]) {
            q = (x[a] - x[a + 1]) / d + 1;
            m += q;
            x[a + 1] += q * d;
        }
    }
    printf("%d\n", m);
    return 0;
}
// END-OF-CODE