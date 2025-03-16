#include <stdio.h>
#include <string.h>

int main() {
    // Read a string from standard input
<<<<<<< HEAD
    char s[100]; // Assuming the maximum length of the string is 99 characters
=======
    char s[100]; // Assuming the input string will not exceed 99 characters
>>>>>>> 98c87cb78a (data updated)
    scanf("%s", s);

    // Initialize variables to keep track of the maximum lengths
    int max_tmp = 0;
    int max = 0;

    // Get the length of the string
    int len = strlen(s);

    // Iterate over each character in the string
    for (int i = 0; i < len; i++) {
<<<<<<< HEAD
        int flag = 0; // Use an integer as a boolean flag
=======
        int flag = 0; // Flag to indicate if a non-ACGT character is found

>>>>>>> 98c87cb78a (data updated)
        // Check if the character is one of 'A', 'C', 'T', 'G'
        switch (s[i]) {
            case 'A':
            case 'C':
            case 'T':
            case 'G':
                // Increment the temporary maximum length counter
                max_tmp++;
                break;
            default:
                // Set the flag to true if the character is not 'A', 'C', 'T', 'G'
                flag = 1;
                break;
        }

        // At the end of the loop, if the flag is true, update the overall maximum length
        if (i == len - 1) {
            flag = 1;
        }
        if (flag == 1) {
            if (max < max_tmp) {
                max = max_tmp;
            }
            // Reset the temporary maximum length counter
            max_tmp = 0;
        }
    }

    // Print the value of the overall maximum length
    printf("%d\n", max);

    return 0;
}

// <END-OF-CODE>
