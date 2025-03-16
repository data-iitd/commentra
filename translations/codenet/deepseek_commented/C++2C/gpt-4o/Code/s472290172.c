#include <stdio.h>

int main() {
<<<<<<< HEAD
    char str[100]; // Assuming the input string will not exceed 99 characters
=======
    char str[1000]; // Assuming the input string will not exceed 999 characters
>>>>>>> 98c87cb78a (data updated)
    scanf("%s", str); // Read the input string from the standard input.

    int max = 0, cnt = 0; // Initialize max and cnt to keep track of the maximum length of consecutive 'A', 'C', 'G', or 'T' characters and the current length of such a sequence.

    for (int i = 0; str[i] != '\0'; i++) { // Iterate over each character in the string until the null terminator.
        char sc = str[i]; // Get the current character.
        if (sc == 'A' || sc == 'C' || sc == 'G' || sc == 'T') { // Check if the character is one of 'A', 'C', 'G', or 'T'.
            cnt++; // If it is, increment the cnt variable.
        } else {
            cnt = 0; // If not, reset cnt to 0.
        }
        max = (max < cnt) ? cnt : max; // After each character, update max to be the maximum of max and cnt.
    }

    printf("%d\n", max); // Print the value of max to the standard output.
<<<<<<< HEAD
    
    return 0; // Return 0 to indicate successful completion of the program.
=======
>>>>>>> 98c87cb78a (data updated)
}

// <END-OF-CODE>
