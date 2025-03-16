#include <stdio.h> // Include the standard input/output library

int main() { // Define the main function, entry point of our program
    // Declare two variables, s and t, both of type char array (string)
    char s[100], t[100];

    // Use the "scanf" function to read input from the standard input (keyboard)
    // and store it in variables s and t respectively
    scanf("%s %s", s, t);

    // Print the concatenated string of t and s using the "printf" function
    printf("%s%s\n", t, s);

    return 0; // Return 0 to indicate successful completion
}

// <END-OF-CODE>
