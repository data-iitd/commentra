
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    // Step 1: Define the input stream and output stream
    FILE * inputStream = stdin;
    FILE * outputStream = stdout;
    
    // Step 2: Create a LightScanner instance for reading input efficiently
    LightScanner in = LightScanner_new(inputStream);
    
    // Step 3: Create a PrintWriter instance for writing output
    FILE * out = stdout;
    
    // Step 4: Create an instance of the problem solver
    BUnhappyHackingABCEdit * solver = BUnhappyHackingABCEdit_new();
    
    // Step 5: Solve the problem
    solver->solve(1, in, out);
    
    // Close the output writer
    fclose(out);
}

// Helper class for solving the problem
typedef struct BUnhappyHackingABCEdit {
    void (*solve)(int testNumber, LightScanner * in, FILE * out);
} BUnhappyHackingABCEdit;

// LightScanner class for reading input efficiently
typedef struct LightScanner {
    FILE * reader;
    char * buffer;
    int bufferLength;
    int bufferPosition;
} LightScanner;

LightScanner * LightScanner_new(FILE * in) {
    LightScanner * self = malloc(sizeof(LightScanner));
    self->reader = in;
    self->buffer = NULL;
    self->bufferLength = 0;
    self->bufferPosition = 0;
    return self;
}

void LightScanner_delete(LightScanner * self) {
    if (self->buffer!= NULL) {
        free(self->buffer);
    }
    free(self);
}

char * LightScanner_next(LightScanner * self) {
    if (self->buffer == NULL) {
        self->buffer = malloc(1024);
        self->bufferLength = fread(self->buffer, 1, 1024, self->reader);
        self->bufferPosition = 0;
    }
    if (self->bufferPosition >= self->bufferLength) {
        return NULL;
    }
    char * result = self->buffer + self->bufferPosition;
    self->bufferPosition += 1;
    return result;
}

char * LightScanner_string(LightScanner * self) {
    char * result = NULL;
    char * token = LightScanner_next(self);
    if (token!= NULL) {
        result = malloc(strlen(token) + 1);
        strcpy(result, token);
    }
    return result;
}

// Helper class for solving the problem
typedef struct BUnhappyHackingABCEdit {
    void (*solve)(int testNumber, LightScanner * in, FILE * out);
} BUnhappyHackingABCEdit;

// LightScanner class for reading input efficiently
typedef struct LightScanner {
    FILE * reader;
    char * buffer;
    int bufferLength;
    int bufferPosition;
} LightScanner;

BUnhappyHackingABCEdit * BUnhappyHackingABCEdit_new() {
    BUnhappyHackingABCEdit * self = malloc(sizeof(BUnhappyHackingABCEdit));
    self->solve = BUnhappyHackingABCEdit_solve;
    return self;
}

void BUnhappyHackingABCEdit_delete(BUnhappyHackingABCEdit * self) {
    free(self);
}

void BUnhappyHackingABCEdit_solve(int testNumber, LightScanner * in, FILE * out) {
    // Read the input string
    char * s = LightScanner_string(in);
    
    // StringBuilder to build the result
    char * d = malloc(1024);
    d[0] = '\0';
    
    // Iterate over each character in the input string
    for (int i = 0; i < strlen(s); i++) {
        switch (s[i]) {
            case '0':
                // Append '0' to the result
                strcat(d, "0");
                break;
            case '1':
                // Append '1' to the result
                strcat(d, "1");
                break;
            case 'B':
                // Remove the last character if the result is not empty
                if (strlen(d) > 0) {
                    d[strlen(d) - 1] = '\0';
                }
                break;
        }
    }
    
    // Print the result
    fprintf(out, "%s\n", d);
}

