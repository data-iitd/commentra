#include <stdio.h>  // For standard input/output operations.
#include <string.h> // For string operations.

#define MAX_STRING_LENGTH 100  // Define a maximum string length.

void print(const char* str) {
    printf("%s\n", str);  // Print a string followed by a newline.
}

// Main function to execute the program.
int main() {
    char S[MAX_STRING_LENGTH];  // Declare a string to hold the input.
    scanf("%s", S);  // Read a string from standard input.

    if (strcmp(S, "Sunny") == 0) {
        print("Cloudy");
    } else if (strcmp(S, "Cloudy") == 0) {
        print("Rainy");
    } else {
        print("Sunny");
    }
<<<<<<< HEAD
    return 0;
=======
    return 0;  // Return 0 to indicate successful execution.
>>>>>>> 98c87cb78a (data updated)
}

// <END-OF-CODE>
