#include <stdio.h>

int main() {
    int x1, y1, x2, y2;
    int a, b;
    int x3, y3, x4, y4;

    scanf("%d %d %d %d", &x1, &y1, &x2, &y2);

    a = x2 - x1;
    b = y2 - y1;

    x3 = x2 - b;
    y3 = y2 + a;
    x4 = x1 - b;
    y4 = y1 + a;

    printf("%d %d %d %d\n", x3, y3, x4, y4);

    return 0;
}

