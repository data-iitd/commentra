#include <stdio.h>
#include <string.h>

<<<<<<< HEAD
// Declare necessary header files for input/output and string manipulation.
=======
// Declare necessary libraries for input/output and string manipulation.
>>>>>>> 98c87cb78a (data updated)

int main() {
    int n;
    char s[100]; // Assuming the string will not exceed 99 characters.

    // Read an integer `n` and a string `s` from the standard input.
    scanf("%d", &n);
    scanf("%s", s);
    
    // Count occurrences of the substring "ABC" in the string `s`.
    int count = 0;
    char *ptr = s;

    // Use a loop to find all occurrences of "ABC".
    while ((ptr = strstr(ptr, "ABC")) != NULL) {
        count++;
<<<<<<< HEAD
        ptr++; // Move past the current occurrence.
=======
        ptr++; // Move past the current found substring to search for more.
>>>>>>> 98c87cb78a (data updated)
    }

    // Print the number of occurrences of the substring "ABC".
    printf("%d\n", count);

    return 0;
}

// <END-OF-CODE>
