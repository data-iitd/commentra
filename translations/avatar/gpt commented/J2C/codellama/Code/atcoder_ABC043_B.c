#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 

// Structure to represent a LightScanner
typedef struct LightScanner { 
    // BufferedReader to read input
    FILE *reader; 
    // StringTokenizer to tokenize input
    char *tokenizer; 
} LightScanner; 

// Function to initialize a LightScanner
void initLightScanner(LightScanner *scanner, FILE *in) { 
    // Initialize the BufferedReader
    scanner->reader = in; 
    // Initialize the StringTokenizer
    scanner->tokenizer = NULL; 
} 

// Function to read the next string token from input
char *string(LightScanner *scanner) { 
    // Check if there are more tokens to read
    if (scanner->tokenizer == NULL || strlen(scanner->tokenizer) == 0) { 
        // Read a new line and create a new StringTokenizer
        char *line = NULL; 
        size_t len = 0; 
        getline(&line, &len, scanner->reader); 
        scanner->tokenizer = strtok(line, " "); 
    } 
    // Return the next token
    return scanner->tokenizer; 
} 

// Structure to represent a BUnhappyHackingABCEdit
typedef struct BUnhappyHackingABCEdit { 
    // StringBuilder to construct the output string
    char *d; 
} BUnhappyHackingABCEdit; 

// Function to initialize a BUnhappyHackingABCEdit
void initBUnhappyHackingABCEdit(BUnhappyHackingABCEdit *solver) { 
    // Initialize the StringBuilder
    solver->d = NULL; 
} 

// Function to solve the problem for a given test case
void solve(int testNumber, LightScanner *in, FILE *out) { 
    // Read the input string
    char *s = string(in); 
    // Initialize the StringBuilder
    initBUnhappyHackingABCEdit(solver); 
    
    // Process each character in the input string
    for (int i = 0; i < strlen(s); i++) { 
        switch (s[i]) { 
            case '0': 
                // Append '0' to the output
                solver->d = strcat(solver->d, "0"); 
                break; 
            case '1': 
                // Append '1' to the output
                solver->d = strcat(solver->d, "1"); 
                break; 
            case 'B': 
                // Handle the 'B' character by removing the last character if possible
                if (strlen(solver->d) > 0) { 
                    solver->d[strlen(solver->d) - 1] = '\0'; // Remove the last character
                    solver->d = realloc(solver->d, strlen(solver->d) + 1); // Adjust the size of the StringBuilder
                } 
                break; 
        } 
    } 
    // Output the final result
    fprintf(out, "%s\n", solver->d); 
} 

// Main function
int main() { 
    // Set up input and output streams
    FILE *inputStream = stdin; 
    FILE *outputStream = stdout; 
    
    // Initialize the LightScanner for reading input
    LightScanner in; 
    initLightScanner(&in, inputStream); 
    
    // Initialize PrintWriter for output
    FILE *out = outputStream; 
    
    // Create an instance of the problem solver
    BUnhappyHackingABCEdit solver; 
    initBUnhappyHackingABCEdit(&solver); 
    
    // Solve the problem for the first test case
    solve(1, &in, out); 
    
    // Close the output stream
    fclose(out); 
} 

