#include <stdio.h>

int main() {
    int a[100]; // Assuming the maximum number of elements is 100
    int n, i;

    // Read a line of input, split it into components, and convert each component to an integer
    scanf("%d", &n); // Read the number of elements
    for (i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    // Iterate over the array 'a' using enumerate to get both the index (i) and the value (a[i])
    for (i = 0; i < n; i++) {
        // Check if the current value is zero
        if (a[i] == 0) {
            // Print the index (1-based) of the first occurrence of zero
            printf("%d\n", i + 1);
            // Exit the loop after finding the first zero
            break;
        }
    }

    return 0;
}
