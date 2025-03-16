#include <stdio.h>

int main(){
    int x1, x2, y1, y2;
    scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
    const int dx = x2 - x1, dy = y2 - y1;
    int x3 = x2 - dy, y3 = y2 + dx;
    int x4 = x1 - dy, y4 = y1 + dx;
    printf("%d %d %d %d\n", x3, y3, x4, y4);
    return 0;
}
