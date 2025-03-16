#include <stdio.h>

int main() {
    // Declare a variable 'n' of type char array (string)
    char n[100];

    // Read a string input from the user using scanf
    scanf("%s", n);

    // Initialize a loop counter 'i'
    for (int i = 0; i < 3; i++) {
        // Check if the current character in the string 'n' is equal to '7'
        if (n[i] == '7') {
            // If yes, print "Yes" and exit the function
            printf("Yes\n");
            return 0;
        }
    }

    // If no '7' is found in the first three characters, print "No"
    printf("No\n");
    return 0;
}

// <END-OF-CODE>
