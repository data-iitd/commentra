#include <stdio.h>

int main() {
    int a, b, c, d;
    scanf("%d %d %d %d", &a, &b, &c, &d);
    printf("%d", max(a * c, b * d, a * d, b * c));
    return 0;
}

