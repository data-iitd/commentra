#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// The main method initializes input and output streams, creates an instance of TaskD, and calls its solve method
int main(int argc, char *argv[]) {
    FILE *inputStream = stdin; // Get the input stream from the system
    FILE *outputStream = stdout; // Get the output stream from the system
    InputReader in = newInputReader(inputStream); // Create an InputReader instance to read input
    PrintWriter out = newPrintWriter(outputStream); // Create a PrintWriter instance to write output
    TaskD solver = newTaskD(); // Create an instance of TaskD
    solver.solve(1, in, out); // Call the solve method of TaskD
    out.close(); // Close the output stream
    return 0;
}

// The TaskD class contains the solve method which calculates a score based on the input string
typedef struct TaskD {
    void (*solve)(int, InputReader, PrintWriter);
} TaskD;

// The InputReader class is used to read input efficiently
typedef struct InputReader {
    FILE *reader; // BufferedReader for reading input
    char *tokenizer; // StringTokenizer for tokenizing input strings
} InputReader;

// The PrintWriter class is used to write output efficiently
typedef struct PrintWriter {
    FILE *writer; // BufferedWriter for writing output
} PrintWriter;

// Constructor for InputReader
InputReader newInputReader(FILE *stream) {
    InputReader in;
    in.reader = stream;
    in.tokenizer = NULL;
    return in;
}

// Constructor for PrintWriter
PrintWriter newPrintWriter(FILE *stream) {
    PrintWriter out;
    out.writer = stream;
    return out;
}

// Method to read the next token from the input stream
char *next(InputReader in) {
    while (in.tokenizer == NULL || strlen(in.tokenizer) == 0) { // Check if there are more tokens
        char *line = NULL;
        size_t size = 0;
        getline(&line, &size, in.reader); // Read the next line and tokenize it
        in.tokenizer = strtok(line, " ");
    }
    char *token = strdup(in.tokenizer); // Return the next token
    in.tokenizer = strtok(NULL, " ");
    return token;
}

// Method to close the output stream
void close(PrintWriter out) {
    fclose(out.writer);
}

// The solve method takes a test number, an InputReader instance, and a PrintWriter instance
void solve(int testNumber, InputReader in, PrintWriter out) {
    char *S = next(in); // Read the next string from the input
    int score = 0; // Initialize the score to 0
    // Iterate through each character in the string S
    for (int i = 0; i < strlen(S); i++) {
        char my = i % 2 == 0 ? 'g' : 'p'; // Determine the expected character based on the index
        char his = S[i]; // Get the character at the current index in S
        // Compare the expected character with the actual character and update the score
        if (my != his) {
            score += my == 'p' ? 1 : -1; // Update the score based on the expected character
        }
    }
    fprintf(out.writer, "%d\n", score); // Print the final score
}

// Constructor for TaskD
TaskD newTaskD() {
    TaskD solver;
    solver.solve = solve;
    return solver;
}

// The end of the code
