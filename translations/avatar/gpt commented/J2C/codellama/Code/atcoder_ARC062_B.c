#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 

// Define the InputReader struct
typedef struct { 
    FILE *reader; 
    char *tokenizer; 
} InputReader; 

// Define the TaskD struct
typedef struct { 
    int testNumber; 
    InputReader *in; 
    FILE *out; 
} TaskD; 

// Function to read the next token from the input
char *next(InputReader *in) { 
    // Keep reading until we have a token available
    while (in->tokenizer == NULL || strlen(in->tokenizer) == 0) { 
        // Read a line and create a new StringTokenizer
        in->tokenizer = (char *) malloc(sizeof(char) * 1000); 
        fgets(in->tokenizer, 1000, in->reader); 
    } 
    // Return the next token
    return in->tokenizer; 
} 

// Function to solve the problem
void solve(TaskD *solver) { 
    // Read the input string S
    char *S = next(solver->in); 
    int score = 0; // Initialize score to zero
    
    // Iterate through each character in the string S
    for (int i = 0; i < strlen(S); i++) { 
        // Determine the character for 'my' based on the index (even or odd)
        char my = i % 2 == 0 ? 'g' : 'p'; 
        
        // Get the character from the input string at the current index
        char his = S[i]; 
        
        // Compare 'my' and 'his' characters to update the score
        if (my != his) { 
            // Increment score if 'my' is 'p', otherwise decrement
            score += my == 'p' ? 1 : -1; 
        } 
    } 
    
    // Output the final score
    fprintf(solver->out, "%d\n", score); 
} 

// Function to create an InputReader
InputReader *createInputReader(FILE *stream) { 
    InputReader *in = (InputReader *) malloc(sizeof(InputReader)); 
    in->reader = stream; 
    in->tokenizer = NULL; 
    return in; 
} 

// Function to create a TaskD
TaskD *createTaskD(int testNumber, InputReader *in, FILE *out) { 
    TaskD *solver = (TaskD *) malloc(sizeof(TaskD)); 
    solver->testNumber = testNumber; 
    solver->in = in; 
    solver->out = out; 
    return solver; 
} 

// Function to solve the problem for a given test number
void solveTest(int testNumber, FILE *inputStream, FILE *outputStream) { 
    // Create an InputReader to read input from the input stream
    InputReader *in = createInputReader(inputStream); 
    
    // Create a PrintWriter to write output to the output stream
    FILE *out = outputStream; 
    
    // Create an instance of TaskD to solve the problem
    TaskD *solver = createTaskD(testNumber, in, out); 
    
    // Call the solve method with test number, input reader, and output writer
    solve(solver); 
    
    // Close the PrintWriter to flush the output
    fclose(out); 
} 

// Function to solve the problem for all test numbers
void solveAllTests(FILE *inputStream, FILE *outputStream) { 
    // Set up input and output streams
    FILE *inputStream = stdin; 
    FILE *outputStream = stdout; 
    
    // Create an InputReader to read input from the input stream
    InputReader *in = createInputReader(inputStream); 
    
    // Create a PrintWriter to write output to the output stream
    FILE *out = outputStream; 
    
    // Create an instance of TaskD to solve the problem
    TaskD *solver = createTaskD(1, in, out); 
    
    // Call the solve method with test number, input reader, and output writer
    solve(solver); 
    
    // Close the PrintWriter to flush the output
    fclose(out); 
} 

int main() { 
    // Set up input and output streams
    FILE *inputStream = stdin; 
    FILE *outputStream = stdout; 
    
    // Create an InputReader to read input from the input stream
    InputReader *in = createInputReader(inputStream); 
    
    // Create a PrintWriter to write output to the output stream
    FILE *out = outputStream; 
    
    // Create an instance of TaskD to solve the problem
    TaskD *solver = createTaskD(1, in, out); 
    
    // Call the solve method with test number, input reader, and output writer
    solve(solver); 
    
    // Close the PrintWriter to flush the output
    fclose(out); 
    
    return 0; 
} 

// 