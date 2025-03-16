
#include <stdio.h>
#include <stdlib.h>

int main() {
    // Read a list of space-separated integers as input from the standard input
    // and convert each integer to its corresponding C integer type using the atoi() function
    int a[100];
    for (int i = 0; i < 100; i++) {
        a[i] = atoi(fgets(stdin, 100, stdin));
    }

    // Iterate over the elements of the list a using the for-loop
    for (int i = 0; i < 100; i++) {
        // Check if the current value is equal to zero
        if (a[i] == 0) {
            // Print the index of the first zero to the standard output
            printf("%d\n", i + 1);
            // Terminate the loop using the break statement
            break;
        }
    }

    return EXIT_SUCCESS;
}

