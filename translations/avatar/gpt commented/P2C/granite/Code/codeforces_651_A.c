
#include <stdio.h>

int main() {
    int x, y;
    scanf("%d %d", &x, &y);
    int result = x + y - 3;
    if (y - x > 0) {
        result += (y - x) / 3;
    }
    printf("%d\n", result < 0? 0 : result);
    return 0;
}

// END-OF-CODE