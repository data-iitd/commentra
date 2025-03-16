#include <stdio.h>

int main() {
    int a[100]; // Assuming a maximum size of 100 for the array
    int n = 0; // To keep track of the number of elements
    int value;

    // Read integers from input
    while (scanf("%d", &value) == 1) {
        a[n++] = value; // Store the value in the array and increment the count
        if (getchar() == '\n') // Break on newline
            break;
    }

    // Find the first occurrence of 0 and print its position
    for (int e = 0; e < n; e++) {
        if (a[e] == 0) {
            printf("%d\n", e + 1); // Print the position (1-based index)
            break;
        }
    }

    return 0;
}

// <END-OF-CODE>
