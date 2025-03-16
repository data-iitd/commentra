#include <stdio.h>

int main() {
    int x, a, b;

    // Reading input values from standard input
    scanf("%d %d %d", &x, &a, &b);

    // Logic block to check if b is less than or equal to a
    if (b - a <= 0) {
        printf("delicious\n");
    }
    // Next case: If b is greater than a but less than or equal to x
    else if (b - a <= x) {
        printf("safe\n");
    }
    // Default case: If none of the above conditions are met
    else {
        printf("dangerous\n");
    }

    return 0;
}

