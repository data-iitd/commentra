
#include <stdio.h> // Include the standard input/output library

int main() {
    int n, i, j, p = 97; // 'p' is initialized to 97, which is the ASCII value for 'a'
    
    // Read an integer input from the user which determines the size of the character array
    scanf("%d", &n);
    
    // Create a character array of size 'n'
    char c[n];
    
    // Fill the character array with letters starting from 'a' (ASCII 97)
    for (i = 0; i < 4; i++) { // Loop through the first 4 positions
        for (j = i; j < n; j += 4) { // Fill every 4th position starting from 'i'
            c[j] = (char) p; // Assign the character corresponding to ASCII value 'p'
            p++; // Increment 'p' to get the next character
        }
    }
    
    // Print the filled character array to the console
    for (i = 0; i < n; i++) {
        printf("%c", c[i]); // Output each character in the array
    }
    
    return 0; // Return 0 to indicate successful execution
}
