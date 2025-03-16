#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 

// Define the InputReader class
typedef struct InputReader { 
    FILE *reader; 
    char *tokenizer; 
} InputReader; 

// Define the CColoringColorfully class
typedef struct CColoringColorfully { 
    char *x; 
    char *a; 
    char *b; 
    int a1; 
    int a2; 
} CColoringColorfully; 

// Method to read the next token from input
char *next(InputReader *in) { 
    // Ensure there are tokens available to read
    while (in->tokenizer == NULL || strlen(in->tokenizer) == 0) { 
        // Read a new line and tokenize it
        in->tokenizer = fgets(in->reader); 
    } 
    // Return the next token
    return strtok(in->tokenizer, " "); 
} 

// Method to solve the problem for a given test case
void solve(int testNumber, InputReader *in, FILE *out) { 
    // Read the input string
    char *x = next(in); 
    
    // Create two StringBuilders to manipulate the string
    char *a = (char *)malloc(strlen(x) + 1); 
    char *b = (char *)malloc(strlen(x) + 1); 
    
    // Initialize counters for the number of changes made
    int a1 = 0; 
    int a2 = 0; 
    
    // First pass: modify 'a' from left to right
    for (int i = 1; i < strlen(x); i++) { 
        // Check if the current character is the same as the previous one
        if (a[i] == a[i - 1]) { 
            // Change the character to the opposite value
            if (a[i] == '1') 
                a[i] = '0'; 
            else 
                a[i] = '1'; 
            
            // Increment the change counter
            a1++; 
        } 
    } 
    
    // Second pass: modify 'b' from right to left
    for (int i = strlen(x) - 1; i > 0; i--) { 
        // Check if the current character is the same as the previous one
        if (b[i] == b[i - 1]) { 
            // Change the previous character to the opposite value
            if (b[i - 1] == '1') 
                b[i - 1] = '0'; 
            else 
                b[i - 1] = '1'; 
            
            // Increment the change counter
            a2++; 
        } 
    } 
    
    // Output the minimum number of changes made in either pass
    fprintf(out, "%d\n", a1 < a2 ? a1 : a2); 
} 

// Main method to solve the problem for the first test case
int main() { 
    // Set up input and output streams
    FILE *inputStream = stdin; 
    FILE *outputStream = stdout; 
    
    // Create an InputReader to read input from the input stream
    InputReader in = { inputStream, NULL }; 
    
    // Create a PrintWriter to write output to the output stream
    FILE *out = outputStream; 
    
    // Instantiate the solver class for the problem
    CColoringColorfully solver = { NULL, NULL, NULL, 0, 0 }; 
    
    // Solve the problem for the first test case
    solve(1, &in, out); 
    
    // Close the output stream
    fclose(out); 
    
    // Return success
    return 0; 
} 

