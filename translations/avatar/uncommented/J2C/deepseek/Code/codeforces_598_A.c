#include <stdio.h>
#include <math.h>

int main() {
    int q;
    scanf("%d", &q);
    while (q-- > 0) {
        int n;
        scanf("%d", &n);
        long s = 0;
        int x = (int)(log(n) / log(2)) + 1;
        s = -1 * (long)pow(2, x) + 2 + (long)n * (n + 1) / 2 - (long)pow(2, x);
        printf("%ld\n", s);
    }
    return 0;
}

