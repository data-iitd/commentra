#include <stdio.h>
#include <string.h>

int main() {
    // Create a buffer to read input
    char input[1000];
    
    // Read a line of input
    fgets(input, sizeof(input), stdin);
    
    // Initialize a counter to keep track of the number of non-zero inputs
    int result = 0;
    
    // Tokenize the input string based on spaces
    char *token = strtok(input, " ");
    
    // Iterate through each token in the input
    while (token != NULL) {
        // Increment the counter for each input
        result += 1;
        
        // If the input is "0", break out of the loop
        if (strcmp(token, "0") == 0) break;
        
        // Get the next token
        token = strtok(NULL, " ");
    }
    
    // Print the result, which is the count of non-zero inputs before the first "0"
    printf("%d\n", result);
    
    return 0;
}
// <END-OF-CODE>
