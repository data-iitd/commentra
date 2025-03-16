
#include <stdio.h>

int min(int n, int a, int b) {
    int min = n * a;
    if (b < min) {
        min = b;
    }
    return min;
}

int main() {
    int n, a, b;
    scanf("%d %d %d", &n, &a, &b);

    printf("%d\n", min(n, a, b));

    return 0;
}
