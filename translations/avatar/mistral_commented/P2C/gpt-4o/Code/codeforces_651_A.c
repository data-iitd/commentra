#include <stdio.h>

int main() {
    int x, y;

    // Read input values for x and y
    scanf("%d %d", &x, &y);

    // Calculate the maximum value
    int result = x + y - 3 + ((y - x) % 3 > 0);
    if (result < 0) {
        result = 0;
    }

    // Print the result
    printf("%d\n", result);

    return 0;
}

// <END-OF-CODE>
