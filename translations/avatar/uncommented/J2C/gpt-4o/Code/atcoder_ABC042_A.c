#include <stdio.h>

int main() {
    int x, a, y;
    char h[4] = "NO"; // Initialize h to "NO"

    // Read input
    scanf("%d %d %d", &x, &a, &y);

    // Check conditions
    if (x == 5 || x == 7 || a == 5 || a == 7 || y == 5 || y == 7) {
        if (x + y + a == 17) {
            snprintf(h, sizeof(h), "YES"); // Update h to "YES"
        }
    }

    // Print result
    printf("%s\n", h);
    return 0;
}
