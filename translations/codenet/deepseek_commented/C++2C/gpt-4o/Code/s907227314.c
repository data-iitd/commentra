<<<<<<< HEAD
#include <stdio.h>  // Include the stdio.h library for input and output operations
=======
#include <stdio.h> // Include the stdio.h library for input and output operations
>>>>>>> 98c87cb78a (data updated)
#include <string.h> // Include the string.h library for string operations

int main() {
    char s[100]; // Declare a character array to store the input string
    scanf("%s", s); // Read input from the user and store it in the character array 's'
<<<<<<< HEAD
    int a = -1, z = -1; // Declare two integer variables to store the positions of 'A' and 'Z', initialized to -1
=======
    int a = -1, z = -1; // Declare two integer variables to store the positions of 'A' and 'Z' and initialize them to -1
>>>>>>> 98c87cb78a (data updated)

    // The first for loop iterates through the string to find the position of the first occurrence of 'A'
    for(int i = 0; i < strlen(s); i++) {
        if (s[i] == 'A') {
<<<<<<< HEAD
            a = i; // Assign the position of 'A' to variable 'a' and break the loop
            break;
=======
            a = i; // Assign the position of 'A' to variable 'a'
            break; // Break the loop after finding the first 'A'
>>>>>>> 98c87cb78a (data updated)
        }
    }

    // The second for loop iterates through the string in reverse to find the position of the last occurrence of 'Z'
    for(int i = strlen(s) - 1; i >= 0; i--) {
        if (s[i] == 'Z') {
<<<<<<< HEAD
            z = i; // Assign the position of 'Z' to variable 'z' and break the loop
            break;
=======
            z = i; // Assign the position of 'Z' to variable 'z'
            break; // Break the loop after finding the last 'Z'
>>>>>>> 98c87cb78a (data updated)
        }
    }

    // Calculate the length of the substring between the first 'A' and the last 'Z' and print it
    if (a != -1 && z != -1) { // Check if both 'A' and 'Z' were found
        printf("%d\n", z - a + 1); // Print the length of the substring
    } else {
        printf("0\n"); // If 'A' or 'Z' is not found, print 0
    }

    return 0; // Return 0 to indicate successful execution
}

// <END-OF-CODE>
