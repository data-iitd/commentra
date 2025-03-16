#include <stdio.h>

int main() {
    int t, n, i;
    scanf("%d", &t);
    for (i = 0; i < t; i++) {
        scanf("%d", &n);
        printf("%d\n", maxLeft(n));
    }
    return 0;
}

int maxLeft(int n) {
    return n > 2 ? n - 2 : 0;
}

