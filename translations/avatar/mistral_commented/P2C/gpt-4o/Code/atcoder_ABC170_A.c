#include <stdio.h>

int main() {
    int a[100]; // Assuming a maximum of 100 integers
    int n = 0; // To keep track of the number of integers read

    // Read space-separated integers from standard input
    while (scanf("%d", &a[n]) == 1) {
        n++;
        if (getchar() == '\n') // Break on newline
            break;
    }

    // Iterate over the elements of the array a
    for (int index = 0; index < n; index++) {
        // Check if the current value is equal to zero
        if (a[index] == 0) {
            // Print the index of the first zero (1-based index)
            printf("%d\n", index + 1);
            // Terminate the loop
            break;
        }
    }

    return 0;
}

// <END-OF-CODE>
