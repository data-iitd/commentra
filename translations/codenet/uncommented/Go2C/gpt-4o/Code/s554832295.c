#include <stdio.h>

int main() {
    int x1, y1, x2, y2;
    scanf("%d %d %d %d", &x1, &y1, &x2, &y2);

    int a = x2 - x1;
    int b = y2 - y1;

    int x3 = x2 - b;
    int y3 = y2 + a;
    int x4 = x1 - b;
    int y4 = y1 + a;

    printf("%d %d %d %d\n", x3, y3, x4, y4);
    return 0;
}

// <END-OF-CODE>
