#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    int x = 0, tmp, count = 0;

    // Read an integer input
    scanf("%d", &x);
    tmp = x;

    // Loop until x becomes 360
    while (x != 360) {
        // Increment x by tmp
        x += tmp;
        // If x exceeds 360, adjust it by subtracting 360
        if (x > 360) {
            x -= 360;
        }
        // Increment the counter
        count++;
    }

    // Print the final count
    printf("%d\n", count);

    return 0;
}
