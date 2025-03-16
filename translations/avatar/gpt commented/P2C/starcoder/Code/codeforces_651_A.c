#include <stdio.h>
#include <stdlib.h>

int main() {
    int x, y;
    scanf("%d %d", &x, &y);
    printf("%d", max(x + y - 3 + ((y - x) % 3 > 0), 0));
    return 0;
}

