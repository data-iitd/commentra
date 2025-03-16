#include <stdio.h>  // Include standard input/output library
#include <string.h> // Include string manipulation functions

int main() {
    int n;                // Declare a variable n to hold the length of the string
    char s[100];         // Declare a character array s to hold the input string (assuming max length of 99)

    // Read input values for n and s from the standard input
    scanf("%d %s", &n, s);

    // Count occurrences of the substring "ABC" in the string s
<<<<<<< HEAD
    int count = 0; // Initialize count of occurrences
    for (int i = 0; i <= n - 3; i++) { // Loop through the string
        if (strncmp(&s[i], "ABC", 3) == 0) { // Check for substring "ABC"
            count++; // Increment count if found
=======
    int count = 0; // Initialize count to 0
    for (int i = 0; i <= n - 3; i++) { // Loop through the string
        if (strncmp(&s[i], "ABC", 3) == 0) { // Check if the substring matches "ABC"
            count++; // Increment count if a match is found
>>>>>>> 98c87cb78a (data updated)
        }
    }

    // Print the count of occurrences
    printf("%d\n", count);

<<<<<<< HEAD
    return 0; // Return success
=======
    return 0; // Return 0 to indicate successful execution
>>>>>>> 98c87cb78a (data updated)
}

// <END-OF-CODE>
