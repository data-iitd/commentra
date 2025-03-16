#include <stdio.h>
#include <string.h>

int main() {
    // Creating a buffer to read input
    char input[1000];
    
    // Reading input array from the console
    fgets(input, sizeof(input), stdin);
    
    // Initializing result variable to 0
    int result = 0;
    
    // Tokenizing the input string based on spaces
    char *token = strtok(input, " ");
    
    // Iterating through each token in the input
    while (token != NULL) {
        // Incrementing result variable for each non-zero string encountered
        result++;
        
        // Breaking the loop if a zero string is encountered
        if (strcmp(token, "0") == 0) break;
        
        // Getting the next token
        token = strtok(NULL, " ");
    }
    
    // Writing the result to the console
    printf("%d\n", result);
    
    return 0;
}
// <END-OF-CODE>
