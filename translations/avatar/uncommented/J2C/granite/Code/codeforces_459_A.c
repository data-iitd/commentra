
#include <stdio.h>
#include <stdlib.h>

int main() {
    int x1, y1, x2, y2;
    scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
    if (x1 == x2) {
        int dif = abs(y1 - y2);
        printf("%d %d %d %d\n", x1 + dif, y1, x1 + dif, y2);
    } else if (y1 == y2) {
        int dif = abs(x1 - x2);
        printf("%d %d %d %d\n", x1, y1 + dif, x2, y2 + dif);
    } else if (abs(x1 - x2) == abs(y1 - y2)) {
        printf("%d %d %d %d\n", x1, y2, x2, y1);
    } else {
        printf("-1\n");
    }
    return 0;
}
//END-OF-CODE