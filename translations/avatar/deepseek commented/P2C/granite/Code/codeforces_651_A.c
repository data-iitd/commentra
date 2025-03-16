
#include <stdio.h>

int main() {
    int x, y;
    scanf("%d %d", &x, &y);
    int result = (x + y - 3) + ((y - x) % 3 > 0);
    result = result > 0? result : 0;
    printf("%d\n", result);
    return 0;
}

// END-OF-CODE