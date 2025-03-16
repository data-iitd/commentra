#include <stdio.h>

int main() {
    int a;
    int b;
    scanf("%d %d", &a, &b);
    int result;
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

