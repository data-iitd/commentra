
#include <stdio.h>

int main() {
    int t;
    scanf("%d", &t);
    for (int i = 0; i < t; i++) {
        int n;
        scanf("%d", &n);
        int s = (1 + n) * n / 2;
        int t = 1;
        while (t <= n) {
            s -= 2 * t;
            t *= 2;
        }
        printf("%d\n", s);
    }
    return 0;
}

