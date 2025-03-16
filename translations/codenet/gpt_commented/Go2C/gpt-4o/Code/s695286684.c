#include <stdio.h>    // Include standard input/output library
#include <string.h>   // Include string manipulation library

// Main function where the execution of the program begins
int main() {
    char s[100]; // Declare a character array 's' to hold the input string

    // Read a string input from the user and store it in variable 's'
    scanf("%s", s);

    // Replace all occurrences of "2017" with "2018" in the input string
    char *pos;
    while ((pos = strstr(s, "2017")) != NULL) {
<<<<<<< HEAD
        // Replace "2017" with "2018"
        strncpy(pos, "2018", 4);
        // Move the rest of the string to the right
        memmove(pos + 4, pos + 4, strlen(pos + 4) + 1);
=======
        // Create a temporary string to hold the modified string
        char temp[100];
        // Copy the part before "2017"
        strncpy(temp, s, pos - s);
        temp[pos - s] = '\0'; // Null-terminate the string
        // Append "2018" to the temporary string
        strcat(temp, "2018");
        // Append the part after "2017"
        strcat(temp, pos + 4); // 4 is the length of "2017"
        // Copy the modified string back to 's'
        strcpy(s, temp);
>>>>>>> 98c87cb78a (data updated)
    }

    // Print the result
    printf("%s\n", s);

    return 0; // Return 0 to indicate successful execution
}

// <END-OF-CODE>
