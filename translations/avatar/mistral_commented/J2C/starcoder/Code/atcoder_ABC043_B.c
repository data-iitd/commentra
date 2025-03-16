
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a structure for a string tokenizer
typedef struct {
    char *str; // String to tokenize
    int length; // Length of the string
    int index; // Current index in the string
} StringTokenizer;

// Initialize a string tokenizer
void StringTokenizer_init(StringTokenizer *tokenizer, char *str) {
    tokenizer->str = str; // Set the string
    tokenizer->length = strlen(str); // Set the length of the string
    tokenizer->index = 0; // Set the index to 0
}

// Get the next token from the string
char *StringTokenizer_next(StringTokenizer *tokenizer) {
    if (tokenizer->index >= tokenizer->length) { // If the index is past the length of the string
        return NULL; // Return NULL
    }
    char *token = malloc(tokenizer->length - tokenizer->index + 1); // Allocate memory for the token
    int i = 0; // Initialize an index
    while (tokenizer->index < tokenizer->length) { // While the index is less than the length of the string
        if (tokenizer->str[tokenizer->index] =='') { // If the current character is a space
            tokenizer->index++; // Increment the index
            break; // Break out of the loop
        }
        token[i++] = tokenizer->str[tokenizer->index++]; // Copy the current character to the token
    }
    token[i] = '\0'; // Terminate the token
    return token; // Return the token
}

// Define a structure for a light scanner
typedef struct {
    StringTokenizer tokenizer; // String tokenizer for tokenizing strings
    char *line; // Line from the input stream
} LightScanner;

// Initialize a light scanner
void LightScanner_init(LightScanner *scanner, char *line) {
    StringTokenizer_init(&scanner->tokenizer, line); // Initialize the string tokenizer
    scanner->line = line; // Set the line
}

// Get the next token from the light scanner
char *LightScanner_next(LightScanner *scanner) {
    return StringTokenizer_next(&scanner->tokenizer); // Return the next token
}

// Define a structure for the solver
typedef struct {
    int testNumber; // Test case number
} Solver;

// Initialize the solver
void Solver_init(Solver *solver) {
    solver->testNumber = 1; // Set the test case number to 1
}

// Define a structure for the problem
typedef struct {
    char *s; // Input string
} Problem;

// Initialize the problem
void Problem_init(Problem *problem, char *s) {
    problem->s = s; // Set the input string
}

// Solve the problem
void Problem_solve(Problem *problem, LightScanner *in, FILE *out) {
    // Read the input string
    char *s = LightScanner_next(in);

    // Initialize an empty string builder for the output
    char *d = malloc(sizeof(char) * 1000000);
    int d_length = 0;

    // Iterate through each character in the input string
    for (int i = 0; i < strlen(s); i++) {
        switch (s[i]) {
            case '0':
                d[d_length++] = '0';
                break;
            case '1':
                d[d_length++] = '1';
                break;
            case 'B':
                if (d_length > 0) {
                    d_length--;
                }
                break;
        }
    }

    // Print the output string to the output stream
    fprintf(out, "%s\n", d);
}

// Define a structure for the program
typedef struct {
    Solver solver; // Solver for the program
    Problem problem; // Problem for the program
} Program;

// Initialize the program
void Program_init(Program *program) {
    Solver_init(&program->solver); // Initialize the solver
    Problem_init(&program->problem, NULL); // Initialize the problem
}

// Run the program
int Program_run(Program *program, FILE *in, FILE *out) {
    // Initialize a light scanner for reading input
    char *line = malloc(sizeof(char) * 1000000);
    fgets(line, 1000000, in);
    LightScanner inScanner;
    LightScanner_init(&inScanner, line);

    // Initialize a string tokenizer for reading input
    StringTokenizer tokenizer;
    StringTokenizer_init(&tokenizer, line);

    // Read the test case number
    char *testNumberToken = StringTokenizer_next(&tokenizer);
    int testNumber = atoi(testNumberToken);

    // Initialize the problem
    Problem_init(&program->problem, NULL);

    // Solve the problem
    Problem_solve(&program->problem, &inScanner, out);

    // Free the memory for the line
    free(line);

    return 0;
}

// Main method that runs the program
int main(int argc, char **argv) {
    Program program; // Program for the program
    Program_init(&program); // Initialize the program
    return Program_run(&program, stdin, stdout); // Run the program
}

