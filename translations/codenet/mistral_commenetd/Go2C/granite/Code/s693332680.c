
#include <stdio.h>

int main() {
    int x, a, b;

    // Reading input values from standard input
    scanf("%d %d %d", &x, &a, &b);

    // Logic block to check if b is less than or equal to a
    if (b - a <= 0) {
        printf("delicious\n");
    } else if (b - a <= x) {
        printf("safe\n");
    } else {
        printf("dangerous\n");
    }

    return 0;
}
// END-OF-CODE