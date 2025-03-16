#include <stdio.h> // Include the stdio library for input and output operations
#include <string.h> // Include the string library for string operations

int main() {
    char s[1000]; // Declare a character array to store the input
    fgets(s, sizeof(s), stdin); // Read input from the user and store it in the character array 's'
    int a, z; // Declare two integer variables to store the positions of 'A' and 'Z'

    // The first for loop iterates through the string to find the position of the first occurrence of 'A'
    for(int i = 0; i < strlen(s); i++) {
        if (s[i] == 'A') {
            a = i; // Assign the position of 'A' to variable 'a' and break the loop
            break;
        }
    }

    // The second for loop iterates through the string in reverse to find the position of the last occurrence of 'Z'
    for(int i = strlen(s) - 1; i >= 0; i--) {
        if (s[i] == 'Z') {
            z = i; // Assign the position of 'Z' to variable 'z' and break the loop
            break;
        }
    }

    // Calculate the length of the substring between the first 'A' and the last 'Z' and print it
    printf("%d\n", z - a + 1);
    return 0; // Return 0 to indicate successful execution
}

