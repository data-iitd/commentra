#include <stdio.h>
#include <math.h>

int main() {
    int x1, y1, x2, y2;
    printf("Enter four integers: ");
    scanf("%d %d %d %d", &x1, &y1, &x2, &y2);

    int denominator = x2 - x1;
    int numerator = y2 - y1;
    double quotient;

    if (denominator != 0) {
        quotient = (double)numerator / denominator;
    }

    if (numerator == 0) {
        int d = (int)sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1));
        int x4 = x1;
        int x3 = x2;
        int y3 = y2 + d;
        int y4 = y1 + d;
        printf("%d %d %d %d\n", x3, y3, x4, y4);
    } else if (denominator == 0) {
        int y4 = y2;
        int y3 = y1;
        int d = (int)sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1));
        int x4 = x1 + d;
        int x3 = x2 + d;
        printf("%d %d %d %d\n", x3, y3, x4, y4);
    } else if (quotient == 1) {
        int x4 = x2;
        int x3 = x1;
        int y4 = y1;
        int y3 = y2;
        printf("%d %d %d %d\n", x3, y3, x4, y4);
    } else if (quotient == -1) {
        int x4 = x1;
        int x3 = x2;
        int y4 = y2;
        int y3 = y1;
        printf("%d %d %d %d\n", x3, y3, x4, y4);
    } else {
        printf("-1\n");
    }

    return 0;
}
