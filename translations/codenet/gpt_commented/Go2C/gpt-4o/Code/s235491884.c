#include <stdio.h>  // Include standard input/output library
<<<<<<< HEAD
#include <string.h> // Include string manipulation library
=======
#include <string.h> // Include string manipulation functions
>>>>>>> 98c87cb78a (data updated)

int main() {
    char s[100]; // Declare a character array 's' to hold the input string
    scanf("%s", s); // Read a string from standard input and store it in 's'

    // Count the occurrences of the letter 'o' in the input string 's'
    int n = 0; // Initialize a counter for 'o'
    for (int i = 0; s[i] != '\0'; i++) { // Loop through each character in the string
        if (s[i] == 'o') { // Check if the character is 'o'
<<<<<<< HEAD
            n++; // Increment the counter if it is 'o'
=======
            n++; // Increment the counter
>>>>>>> 98c87cb78a (data updated)
        }
    }

    // Calculate the result based on the count of 'o' and print it
    // The formula adds 700 to 100 times the count of 'o'
    printf("%d\n", 700 + n * 100);

    return 0; // Return 0 to indicate successful completion
}

// <END-OF-CODE>
