<<<<<<< HEAD
#include <stdio.h> // Include the standard I/O library for input and output
=======
#include <stdio.h> // Include the stdio.h library for input and output
#include <string.h> // Include the string.h library for string manipulation
>>>>>>> 98c87cb78a (data updated)

int main() {
    char str[100]; // Declare a character array to hold user input

    // Read a string input from the user
    scanf("%s", str);

    // Check if the characters at positions 2 and 3 are the same,
    // and if the characters at positions 4 and 5 are the same
    if (str[2] == str[3] && str[4] == str[5]) 
        printf("Yes\n"); // If both conditions are true, output "Yes"
    else 
        printf("No\n"); // If either condition is false, output "No"
<<<<<<< HEAD
=======

    return 0; // Return 0 to indicate successful completion
>>>>>>> 98c87cb78a (data updated)
}

// <END-OF-CODE>
