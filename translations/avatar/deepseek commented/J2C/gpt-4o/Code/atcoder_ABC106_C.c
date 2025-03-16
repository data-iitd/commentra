#include <stdio.h>
#include <string.h>

int main() {
    char str[100]; // Step 1: Declare a string to read input
    scanf("%s", str); // Step 2: Read the input string
    long k; // Step 4: Declare a variable for k
    scanf("%ld", &k); // Read the value of k
    int n = strlen(str); // Step 5: Initialize the length of the string

    for (int i = 0; i < k; i++) { // Step 6: Loop through the character array k times
        if (str[i] == '1') { // Step 7: Check if the character at the current index is '1'
            if (i == k - 1) { // Step 8: Check if the current index is the last index
                printf("1\n"); // Step 9: Print '1' and return
                return 0; 
            }
        } else { // Step 10: If it is not '1'
            printf("%c\n", str[i]); // Step 11: Print the character and return
            return 0; 
        }
    }
    return 0; // Return 0 to indicate successful completion
}

// <END-OF-CODE>
