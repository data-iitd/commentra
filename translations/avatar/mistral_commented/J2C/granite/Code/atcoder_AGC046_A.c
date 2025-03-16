
#include <stdio.h>

int main() {
    int x, tmp, count = 0;
    scanf("%d", &x);
    tmp = x;
    x = 0;
    while (x < 360) {
        x += tmp;
        if (x > 360) {
            x -= 360;
        }
        count++;
    }
    printf("%d", count);
    return 0;
}
