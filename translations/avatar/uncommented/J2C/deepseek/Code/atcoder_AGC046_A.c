#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    int x, count = 0, tmp, i;
    scanf("%d", &x);
    tmp = x;
    x = 0;
    for (i = 0; i < 360; i++) {
        x = x + tmp;
        if (x > 360) {
            x = x - 360;
        }
        count++;
    }
    printf("%d\n", count);
    return 0;
}
