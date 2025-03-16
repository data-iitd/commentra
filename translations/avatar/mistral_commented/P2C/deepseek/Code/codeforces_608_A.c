#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, s, c = 0, f, t, x;
    scanf("%d %d", &n, &s);

    for (int i = 0; i < n; i++) {
        scanf("%d %d", &f, &t);
        x = t - (s - f);
        if (x > c) {
            c = x;
        }
    }

    printf("%d\n", s + c);
    return 0;
}

