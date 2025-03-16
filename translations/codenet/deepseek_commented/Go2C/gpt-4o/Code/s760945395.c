#include <stdio.h>

int main() {
    // The code starts a loop that will run 5 times
    for (int i = 0; i < 5; i++) {
        // Declares an integer variable 'a' to store the input
        int a;
        // Reads an integer input from the user and stores it in 'a'
        scanf("%d", &a);
        // Checks if the input is 0
        if (a == 0) {
            // Prints the current iteration number (starting from 1)
            printf("%d\n", i + 1);
        }
    }
    return 0;
}
// <END-OF-CODE>
