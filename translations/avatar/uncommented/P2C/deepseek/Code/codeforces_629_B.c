#include <stdio.h>
#include <stdlib.h>

#define N 368

int main() {
    int m[N] = {0};
    int f[N] = {0};
    int i, n;
    scanf("%d", &n);
    getchar(); // to consume the newline character after the integer input

    for (i = 0; i < n; i++) {
        char x[2];
        int a, b;
        scanf("%s %d %d", x, &a, &b);
        b++;
        if (x[0] == 'M') {
            m[a] += 2;
            m[b] -= 2;
        } else {
            f[a] += 2;
            f[b] -= 2;
        }
    }

    int a = 0, b = 0, c = 0;
    for (i = 0; i < N; i++) {
        a += m[i];
        b += f[i];
        if (a < b && a < c) {
            c = a;
        } else if (b < a && b < c) {
            c = b;
        }
    }

    printf("%d\n", c);
    return 0;
}
