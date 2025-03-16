#include <stdio.h> // Include the necessary header file for input and output operations
<<<<<<< HEAD
#include <string.h> // Include the string header for string operations
=======
#include <string.h> // Include the header file for string operations
>>>>>>> 98c87cb78a (data updated)

int main() { // The main function is the entry point of the program
    char str[100]; // Declare a character array to store the input string
    scanf("%s", str); // Input the string from the user and store it in the character array str

    // Check if the characters at positions 2 and 3 are the same and if the characters at positions 4 and 5 are the same
    if (str[2] == str[3] && str[4] == str[5]) 
        printf("Yes\n"); // If the conditions are met, output "Yes"
    else 
        printf("No\n"); // If the conditions are not met, output "No"
    
    return 0; // Return 0 to indicate successful completion of the program
}

// <END-OF-CODE>
