#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

int main() {
    // Set up the standard input and output streams
    FILE * inputStream = stdin;
    FILE * outputStream = stdout;
    // Create an InputReader to read input from the standard input stream
    InputReader in = InputReader_new(inputStream);
    // Create a PrintWriter to write output to the standard output stream
    PrintWriter out = PrintWriter_new(outputStream);
    // Create an instance of TaskB and call its solve method
    TaskB solver = TaskB_new();
    solver->solve(1, in, out);
    // Close the PrintWriter to flush the output and close the stream
    PrintWriter_close(out);
    return 0;
}

// TaskB class contains the main logic of the program
typedef struct TaskB TaskB;
struct TaskB {
    // The solve method implements the main logic
    void (*solve)(TaskB *self, int testNumber, InputReader in, PrintWriter out);
};

// Helper class to read input from the standard input stream
typedef struct InputReader InputReader;
struct InputReader {
    FILE * inputStream;
    char * buffer;
    size_t capacity;
    size_t position;
};

// Helper class to write output to the standard output stream
typedef struct PrintWriter PrintWriter;
struct PrintWriter {
    FILE * outputStream;
};

// Constructor to initialize the InputReader with the standard input stream
InputReader * InputReader_new(FILE * inputStream) {
    InputReader * self = (InputReader *) malloc(sizeof(InputReader));
    self->inputStream = inputStream;
    self->buffer = NULL;
    self->capacity = 0;
    self->position = 0;
    return self;
}

// Method to read the next token from the input stream
char * InputReader_next(InputReader * self) {
    if (self->buffer == NULL) {
        self->buffer = (char *) malloc(1024);
        self->capacity = 1024;
        self->position = 0;
    }
    if (self->position == self->capacity) {
        self->capacity *= 2;
        self->buffer = (char *) realloc(self->buffer, self->capacity);
    }
    self->buffer[self->position] = '\0';
    size_t length = 0;
    while (true) {
        int c = fgetc(self->inputStream);
        if (c == -1) {
            break;
        }
        if (c =='' || c == '\n' || c == '\t' || c == '\r') {
            if (length > 0) {
                break;
            }
        } else {
            self->buffer[self->position++] = c;
            length++;
        }
    }
    return self->buffer;
}

// Constructor to initialize the PrintWriter with the standard output stream
PrintWriter * PrintWriter_new(FILE * outputStream) {
    PrintWriter * self = (PrintWriter *) malloc(sizeof(PrintWriter));
    self->outputStream = outputStream;
    return self;
}

// Method to write a string to the standard output stream
void PrintWriter_print(PrintWriter * self, char * string) {
    fprintf(self->outputStream, "%s", string);
}

// Method to write a newline to the standard output stream
void PrintWriter_println(PrintWriter * self) {
    fprintf(self->outputStream, "\n");
}

// Method to flush the standard output stream
void PrintWriter_flush(PrintWriter * self) {
    fflush(self->outputStream);
}

// Method to close the standard output stream
void PrintWriter_close(PrintWriter * self) {
    fclose(self->outputStream);
}

// Constructor to initialize the TaskB with default values
TaskB * TaskB_new() {
    TaskB * self = (TaskB *) malloc(sizeof(TaskB));
    self->solve = (void (*)(TaskB *, int, InputReader, PrintWriter)) &TaskB_solve;
    return self;
}

// The solve method implements the main logic
void TaskB_solve(TaskB * self, int testNumber, InputReader in, PrintWriter out) {
    // Read the input string
    char * x = InputReader_next(in);
    // Initialize a stack to keep track of characters
    Stack * s = Stack_new();
    // Initialize a counter to count balanced pairs
    int c = 0;
    // Iterate through each character in the input string
    for (int i = 0; i < strlen(x); i++) {
        // Push the current character onto the stack
        Stack_push(s, x[i]);
        // While the stack has more than one element, check for balanced pairs
        while (Stack_size(s) > 1) {
            // Pop the top two elements from the stack
            char p = Stack_pop(s);
            char q = Stack_pop(s);
            // Check if they form a balanced pair
            if ((p == '1' && q == '0') || (p == '0' && q == '1')) {
                // Increment the counter if a balanced pair is found
                c++;
                continue;
            } else {
                // If not a balanced pair, push the popped elements back onto the stack
                Stack_push(s, q);
                Stack_push(s, p);
                break;
            }
        }
    }
    // Output the result, which is twice the counter value
    char * result = (char *) malloc(1024);
    sprintf(result, "%d", c * 2);
    PrintWriter_print(out, result);
    PrintWriter_println(out);
}

// Helper class to implement a stack
typedef struct Stack Stack;
struct Stack {
    void * array;
    size_t size;
    size_t capacity;
};

// Constructor to initialize the Stack with default values
Stack * Stack_new() {
    Stack * self = (Stack *) malloc(sizeof(Stack));
    self->array = NULL;
    self->size = 0;
    self->capacity = 0;
    return self;
}

// Method to get the size of the stack
size_t Stack_size(Stack * self) {
    return self->size;
}

// Method to check if the stack is empty
bool Stack_isEmpty(Stack * self) {
    return self->size == 0;
}

// Method to get the top element of the stack
void * Stack_peek(Stack * self) {
    if (self->size == 0) {
        return NULL;
    }
    return self->array[self->size - 1];
}

// Method to push an element onto the stack
void Stack_push(Stack * self, void * element) {
    if (self->size == self->capacity) {
        if (self->capacity == 0) {
            self->capacity = 1;
        } else {
            self->capacity *= 2;
        }
        self->array = (void **) realloc(self->array, self->capacity);
    }
    self->array[self->size++] = element;
}

// Method to pop an element from the stack
void * Stack_pop(Stack * self) {
    if (self->size == 0) {
        return NULL;
    }
    void * element = self->array[self->size - 1];
    self->array[self->size - 1] = NULL;
    self->size--;
    return element;
}

// Method to free the memory taken up by the stack
void Stack_free(Stack * self) {
    free(self->array);
    free(self);
}

