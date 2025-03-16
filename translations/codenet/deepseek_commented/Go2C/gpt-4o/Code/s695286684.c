#include <stdio.h>
#include <string.h>

int main() {
<<<<<<< HEAD
    char s[100]; // Declare a string with a maximum length of 100 characters
=======
    char s[100]; // Assuming the input string will not exceed 99 characters
>>>>>>> 98c87cb78a (data updated)
    // Read a string from the standard input and store it in the variable 's'.
    scanf("%s", s);
    
    // Replace all occurrences of "2017" with "2018" in the string 's'.
    char *pos;
    while ((pos = strstr(s, "2017")) != NULL) {
        // Replace "2017" with "2018"
        strncpy(pos, "2018", 4); // Copy "2018" into the position of "2017"
<<<<<<< HEAD
        // Move the rest of the string forward
        memmove(pos + 4, pos + 4, strlen(pos + 4) + 1);
    }
    
    // Print the result
=======
        // Move the rest of the string to the right
        memmove(pos + 4, pos + 4, strlen(pos + 4) + 1); // +1 for the null terminator
    }
    
    // Print the result.
>>>>>>> 98c87cb78a (data updated)
    printf("%s\n", s);
    
    return 0;
}

// <END-OF-CODE>
