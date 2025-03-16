#include <stdio.h>

int main() {
    int x, y;
    scanf("%d %d", &x, &y);

    // Calculate and print the maximum value between x + y - 3 + ( ( y - x ) % 3 > 0 ) and 0
    int result = (x + y - 3 + ((y - x) % 3 > 0));
    printf("%d\n", result > 0 ? result : 0);

    return 0;
}
