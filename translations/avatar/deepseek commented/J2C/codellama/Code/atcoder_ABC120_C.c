#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <stdint.h>

#define MAX_INPUT_LENGTH 1000000

typedef struct {
    char *input;
    int length;
    int index;
} InputReader;

InputReader *new_input_reader(char *input) {
    InputReader *reader = malloc(sizeof(InputReader));
    reader->input = input;
    reader->length = strlen(input);
    reader->index = 0;
    return reader;
}

char *next(InputReader *reader) {
    char *token = malloc(sizeof(char) * MAX_INPUT_LENGTH);
    int i = 0;
    while (reader->index < reader->length && reader->input[reader->index] != ' ') {
        token[i++] = reader->input[reader->index++];
    }
    token[i] = '\0';
    reader->index++;
    return token;
}

typedef struct {
    char *input;
    int length;
    int index;
} Stack;

Stack *new_stack() {
    Stack *stack = malloc(sizeof(Stack));
    stack->input = malloc(sizeof(char) * MAX_INPUT_LENGTH);
    stack->length = 0;
    stack->index = 0;
    return stack;
}

void push(Stack *stack, char c) {
    stack->input[stack->length++] = c;
}

char pop(Stack *stack) {
    return stack->input[--stack->length];
}

bool is_empty(Stack *stack) {
    return stack->length == 0;
}

int main() {
    // Set up the standard input and output streams
    char input[MAX_INPUT_LENGTH];
    fgets(input, MAX_INPUT_LENGTH, stdin);
    InputReader *in = new_input_reader(input);
    // Create an instance of TaskB and call its solve method
    TaskB *solver = new_task_b();
    solver->solve(1, in, stdout);
    // Close the PrintWriter to flush the output and close the stream
    fclose(stdout);
    return 0;
}

// TaskB class contains the main logic of the program
typedef struct {
    char *input;
    int length;
    int index;
} TaskB;

TaskB *new_task_b() {
    TaskB *solver = malloc(sizeof(TaskB));
    solver->input = malloc(sizeof(char) * MAX_INPUT_LENGTH);
    solver->length = 0;
    solver->index = 0;
    return solver;
}

void solve(TaskB *solver, int testNumber, InputReader *in, FILE *out) {
    // Read the input string
    char *x = next(in);
    // Initialize a stack to keep track of characters
    Stack *s = new_stack();
    // Initialize a counter to count balanced pairs
    int c = 0;
    // Iterate through each character in the input string
    for (int i = 0; i < strlen(x); i++) {
        // Push the current character onto the stack
        push(s, x[i]);
        // While the stack has more than one element, check for balanced pairs
        while (!is_empty(s) && s->length > 1) {
            // Pop the top two elements from the stack
            char p = pop(s);
            char q = pop(s);
            // Check if they form a balanced pair
            if ((p == '1' && q == '0') || (p == '0' && q == '1')) {
                // Increment the counter if a balanced pair is found
                c++;
                continue;
            } else {
                // If not a balanced pair, push the popped elements back onto the stack
                push(s, q);
                push(s, p);
                break;
            }
        }
    }
    // Output the result, which is twice the counter value
    fprintf(out, "%d\n", c * 2);
}

