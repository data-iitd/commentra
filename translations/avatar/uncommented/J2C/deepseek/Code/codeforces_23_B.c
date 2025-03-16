#include <stdio.h>

int maxLeft(int n) {
    return n > 2 ? n - 2 : 0;
}

int main() {
    int t, n;
    scanf("%d", &t);
    for (int i = 0; i < t; i++) {
        scanf("%d", &n);
        printf("%d\n", maxLeft(n));
    }
    return 0;
}

