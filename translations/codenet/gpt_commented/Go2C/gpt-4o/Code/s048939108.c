#include <stdio.h>
#include <string.h>
<<<<<<< HEAD
=======
#include <stdlib.h>
>>>>>>> 98c87cb78a (data updated)

#define BUFFER_SIZE 1000

// Function to check if a string starts with a given prefix
int startsWith(const char *str, const char *prefix) {
    return strncmp(str, prefix, strlen(prefix)) == 0;
}

int main() {
<<<<<<< HEAD
    char buffer[BUFFER_SIZE];

    // Read a string from the input
    fgets(buffer, BUFFER_SIZE, stdin);
    
    // Remove the newline character from the input if present
=======
    char buffer[BUFFER_SIZE]; // Buffer to hold input
    // Read a string from the input
    fgets(buffer, BUFFER_SIZE, stdin);
    
    // Remove newline character from the input if present
>>>>>>> 98c87cb78a (data updated)
    buffer[strcspn(buffer, "\n")] = 0;

    // Check if the string starts with "YAKI" and print the corresponding response
    if (startsWith(buffer, "YAKI")) {
        printf("Yes\n");
    } else {
        printf("No\n");
    }

    return 0;
}

// min returns the smaller of two integers
int min(int a, int b) {
    return (a < b) ? a : b;
}

// max returns the larger of two integers
int max(int a, int b) {
    return (a > b) ? a : b;
}

<<<<<<< HEAD
// Note: The scanner functionality is not included as it is not needed for this specific translation.
// <END-OF-CODE>
=======
// Note: The additional functions for reading integers and arrays are not included
// as they are not used in the provided Go code. If needed, they can be implemented similarly.

>>>>>>> 98c87cb78a (data updated)
