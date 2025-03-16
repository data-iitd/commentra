# Including the stdio.h header file for reading input from the standard input
# and the stdlib.h header file for using the atoi function
# for converting the string to integer
# and the math.h header file for using the min function
# for finding the minimum of two integers
# and the string.h header file for using the strtok function
# for tokenizing the input string
# and the stdbool.h header file for using the bool type
# and the assert.h header file for using the assert function
# for checking the validity of the input
# and the limits.h header file for using the INT_MAX constant
# for checking the validity of the input
# and the time.h header file for using the clock function
// for measuring the time of execution
# and the stdlib.h header file for using the malloc and free functions
// for dynamically allocating and deallocating memory
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <stdbool.h>
#include <assert.h>
#include <limits.h>
#include <time.h>

// Defining the function readline for reading a line from the standard input
char* readline() {
    // Initializing the variables for reading the input
    char* line = NULL;
    size_t len = 0;
    ssize_t n;

    // Reading the input from the standard input
    n = getline(&line, &len, stdin);

    // Returning the input string
    return line;
}

// Defining the function tokenize for tokenizing the input string
char** tokenize(char* line) {
    // Initializing the variables for tokenizing the input
    char** tokens = NULL;
    char* token;
    int count = 0;

    // Tokenizing the input string
    token = strtok(line, " ");

    // Looping until the end of the input string
    while (token != NULL) {
        // Incrementing the count of tokens
        count++;

        // Reallocating the memory for the tokens array
        tokens = realloc(tokens, sizeof(char*) * count);

        // Storing the token in the tokens array
        tokens[count - 1] = token;

        // Finding the next token
        token = strtok(NULL, " ");
    }

    // Returning the tokens array
    return tokens;
}

// Defining the function get_int for converting the string to integer
int get_int(char* token) {
    // Converting the string to integer
    int value = atoi(token);

    // Returning the integer value
    return value;
}

// Defining the function get_operation for processing each operation
void get_operation(char* operation, int* m, int* f) {
    // Tokenizing the operation string
    char** tokens = tokenize(operation);

    // Converting the first token to integer
    int a = get_int(tokens[0]);

    // Converting the second token to integer
    int b = get_int(tokens[1]);

    // If the operation is 'M', updating the m array accordingly
    if (strcmp(tokens[2], "M") == 0) {
        m[a] += 2;
        m[b] -= 2;
    }
    // If the operation is 'F', updating the f array accordingly
    else {
        f[a] += 2;
        f[b] -= 2;
    }

    // Freeing the memory allocated for the tokens array
    free(tokens);
}

// Defining the function get_min for finding the minimum of two integers
int get_min(int a, int b) {
    // Finding the minimum of a and b
    int min = min(a, b);

    // Returning the minimum
    return min;
}

// Defining the function get_sum for calculating the prefix sums of m and f arrays
void get_sum(int* m, int* f, int* a, int* b, int* c) {
    // Initializing the variables for calculating the prefix sums
    int i;

    // Calculating the prefix sums of m and f arrays
    for (i = 0; i < 368; i++) {
        // Updating the variables a and b with the sum of m and f arrays respectively
        *a += m[i];
        *b += f[i];

        // Finding the minimum of a and b and updating the variable c if the minimum is greater than the current value of c
        if (get_min(*a, *b) > *c) {
            *c = get_min(*a, *b);
        }
    }
}

// Defining the main function
int main() {
    // Initializing the variables for reading the input
    char* line = NULL;
    int i;

    // Reading the number of operations from the standard input
    int n = get_int(readline());

    // Initializing the arrays m and f with zeros for all indices up to N
    int m[368] = {0};
    int f[368] = {0};

    // Reading the operations from the standard input and processing each operation
    for (i = 0; i < n; i++) {
        get_operation(readline(), m, f);
    }

    // Initializing the variables a, b, and c with zeros
    int a = 0;
    int b = 0;
    int c = 0;

    // Calculating the prefix sums of m and f arrays
    get_sum(m, f, &a, &b, &c);

    // Printing the result, which is the minimum of the prefix sums of m and f arrays
    printf("%d\n", c);

    // Freeing the memory allocated for the line variable
    free(line);

    // Returning 0 to indicate successful execution
    return 0;
}

