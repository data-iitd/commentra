#include <stdio.h>

int main() {
    int n, s, c = 0;
    scanf("%d %d", &n, &s);
    for (int i = 0; i < n; i++) {
        int f, t;
        scanf("%d %d", &f, &t);
        int x = t - (s - f);
        if (x > c) {
            c = x;
        }
    }
    printf("%d\n", s + c);
    return 0;
}

