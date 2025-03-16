

#include <stdio.h>

int main() {
    int x, y;
    scanf("%d %d", &x, &y);
    printf("%d", (x + y - 3 + ((y - x) % 3 > 0)) > 0? (x + y - 3 + ((y - x) % 3 > 0)) : 0);
    return 0;
}

