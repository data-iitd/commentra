#include <stdio.h>
#include <stdlib.h>

#define N 368

int main() {
    int m[N] = {0};
    int f[N] = {0};
    int a = 0, b = 0, c = 0;
    int n;
    scanf("%d", &n);
    getchar(); // Consume the newline character after the number of operations

    for (int i = 0; i < n; i++) {
        char x;
        int a, b;
        scanf("%c %d %d", &x, &a, &b);
        b++; // Adjusting the end index by 1
        if (x == 'M') {
            m[a] += 2;
            m[b] -= 2;
        } else {
            f[a] += 2;
            f[b] -= 2;
        }
        getchar(); // Consume the newline character
    }

    for (int i = 0; i < N; i++) {
        a += m[i];
        b += f[i];
        if (a < b && a > c) {
            c = a;
        } else if (b < a && b > c) {
            c = b;
        }
    }

    printf("%d\n", c);
    return 0;
}
