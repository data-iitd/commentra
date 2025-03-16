#include <stdio.h> // Including the standard input-output library
#include <string.h> // Including the string library for string manipulation functions

int main() {
    char s[100]; // Declaring a character array to store user input
    scanf("%s", s); // Reading input from the user and storing it in the array s

    int n = 0; // Initializing a counter for occurrences of 'o'
    for (int i = 0; s[i] != '\0'; i++) { // Looping through the string until the null terminator
        if (s[i] == 'o') { // Checking if the current character is 'o'
            n++; // Incrementing the counter if 'o' is found
        }
    }

    printf("%d\n", 700 + n * 100); // Printing the final score based on the count of 'o' characters
    return 0; // Returning 0 to indicate successful execution
}

// <END-OF-CODE>
