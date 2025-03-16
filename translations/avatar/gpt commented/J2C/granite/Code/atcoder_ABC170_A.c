
#include <stdio.h>
#include <string.h>

int main() {
    // Create a character array to store the input string
    char input[100];
    
    // Read a line of input from the standard input stream
    fgets(input, sizeof(input), stdin);
    
    // Remove the newline character from the end of the input string
    input[strcspn(input, "\n")] = 0;
    
    // Initialize a counter to keep track of the number of non-zero inputs
    int result = 0;
    
    // Iterate through each character in the input string
    for (char *p = input; *p!= '\0'; p++) {
        // Increment the counter for each non-zero input
        if (*p!= '0') {
            result++;
        }
    }
    
    // Print the result, which is the count of non-zero inputs
    printf("%d\n", result);
    
    return 0;
}
