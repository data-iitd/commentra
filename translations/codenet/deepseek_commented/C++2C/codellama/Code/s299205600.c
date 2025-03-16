#include <stdio.h>
#include <stdlib.h>

int main() {
    int a, b, result;
    scanf("%d %d", &a, &b);

    if (a > b) {
        result = 2 * a - 1;
    } else if (a == b) {
        result = 2 * a;
    } else {
        result = 2 * b - 1;
    }

    printf("%d\n", result);

    return 0;
}

