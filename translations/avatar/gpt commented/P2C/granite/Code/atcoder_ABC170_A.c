
#include <stdio.h>

int main() {
    int a[100];
    int i, e;

    // Read a line of input, split it into components, and convert each component to an integer
    for (i = 0; i < 100; i++) {
        scanf("%d", &a[i]);
    }

    // Iterate over the array 'a' using a for loop
    for (e = 0; e < 100; e++) {
        // Check if the current value is zero
        if (a[e] == 0) {
            // Print the index (1-based) of the first occurrence of zero
            printf("%d", e + 1);
            // Exit the loop after finding the first zero
            break;
        }
    }

    return 0;
}
