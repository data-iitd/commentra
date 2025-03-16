#include <stdio.h>

int main() {
    // Initialize a for loop that will iterate 5 times
    for (int i = 0; i < 5; i++) {
        // Declare and initialize a variable 'a' to store user input
        int a;

        // Request user input and store it in variable 'a'
        scanf("%d", &a);

        // Check if the user input is equal to zero
        if (a == 0) {
            // If user input is zero, print the current iteration number
            printf("%d\n", i + 1);
        }
    }
    return 0;
}

// <END-OF-CODE>
