#include <stdio.h>

int main() {
    int a[100]; // Assuming a maximum of 100 integers
    int n = 0; // To keep track of the number of integers read

    // Read a line of input and split it into components
    while (scanf("%d", &a[n]) == 1) {
        n++;
        if (getchar() == '\n') // Break on newline
            break;
    }

    // Iterate over the array 'a'
    for (int e = 0; e < n; e++) {
        // Check if the current value is zero
        if (a[e] == 0) {
            // Print the index (1-based) of the first occurrence of zero
            printf("%d\n", e + 1);
            // Exit the loop after finding the first zero
            break;
        }
    }

    return 0;
}
// <END-OF-CODE>
