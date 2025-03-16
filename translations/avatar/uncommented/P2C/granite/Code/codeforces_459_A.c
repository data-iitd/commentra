
#include <stdio.h>
#include <math.h>

int main() {
    int x1, y1, x2, y2;
    scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
    int denominator = x2 - x1;
    int numerator = y2 - y1;
    if (denominator!= 0) {
        float quotient = (float) numerator / denominator;
        if (numerator == 0) {
            int d = sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
            int x3 = x1, x4 = x2, y3 = y2 + d, y4 = y1 + d;
            printf("%d %d %d %d", x3, y3, x4, y4);
        } else if (denominator == 0) {
            int d = sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
            int x3 = x1 + d, x4 = x2 + d, y3 = y1, y4 = y2;
            printf("%d %d %d %d", x3, y3, x4, y4);
        } else if (quotient == 1) {
            int x3 = x2, x4 = x1, y3 = y1, y4 = y2;
            printf("%d %d %d %d", x3, y3, x4, y4);
        } else if (quotient == -1) {
            int x3 = x1, x4 = x2, y3 = y2, y4 = y1;
            printf("%d %d %d %d", x3, y3, x4, y4);
        } else {
            printf("-1");
        }
    }
    return 0;
}
//END-OF-CODE