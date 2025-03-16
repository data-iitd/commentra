
#include <stdio.h>
#define N 368

int main(void) {
    int i, j, k, a, b, c, x, m[N], f[N];
    for (i = 0; i < N; i++) {
        m[i] = 0;
        f[i] = 0;
    }
    scanf("%d", &k);
    for (i = 0; i < k; i++) {
        scanf("%d %d %d", &x, &a, &b);
        if (x == 1) {
            m[a] += 2;
            m[b] -= 2;
        } else {
            f[a] += 2;
            f[b] -= 2;
        }
    }
    a = 0;
    b = 0;
    c = 0;
    for (i = 0; i < N; i++) {
        a += m[i];
        b += f[i];
        if (a < b) {
            j = a;
        } else {
            j = b;
        }
        if (c < j) {
            c = j;
        }
    }
    printf("%d\n", c);
    return 0;
}
