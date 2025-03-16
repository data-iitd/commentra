
#include <stdio.h>

int main() {
    int a, b, result;

    scanf("%d", &a);
    scanf("%d", &b);

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

