#include <stdio.h>
#include <string.h>

int main() {
    char stdin[100];  // Declare a character array to store user input
    fgets(stdin, sizeof(stdin), stdin);  // Take input from the user and store it in stdin

    // Check if the string contains both 'A' and 'B'
    if (strchr(stdin, 'A') != NULL && strchr(stdin, 'B') != NULL) {
        printf("Yes\n");  // If both 'A' and 'B' are in the string, print "Yes"
    } else {
        printf("No\n");  // Otherwise, print "No"
    }

    return 0;  // Return 0 to indicate successful execution
}  // End of main function

// <END-OF-CODE>
