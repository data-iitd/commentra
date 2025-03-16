#######
# Code
#######

# Include necessary libraries
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

// Define constants
#define inf 100000000
#define mod 1000000007
#define dd 8
#define ddn 9

// Function to read an integer list from standard input
int* LI( int* n ) {
    *n = 0;
    char* line = NULL;
    size_t len = 0;
    ssize_t read;
    int* list = NULL;
    while ( (read = getline(&line, &len, stdin)) != -1 ) {
        int i = 0;
        char* token = strtok(line, " ");
        while ( token != NULL ) {
            list = (int*)realloc(list, (*n + 1) * sizeof(int));
            list[*n] = atoi(token);
            i++;
            token = strtok(NULL, " ");
        }
        *n += i;
    }
    return list;
}

// Function to read an integer from standard input
int I(  ) {
    int x = 0;
    char* line = NULL;
    size_t len = 0;
    ssize_t read;
    while ( (read = getline(&line, &len, stdin)) != -1 ) {
        x = atoi(line);
    }
    return x;
}

// Function to read a float from standard input
float F(  ) {
    float x = 0;
    char* line = NULL;
    size_t len = 0;
    ssize_t read;
    while ( (read = getline(&line, &len, stdin)) != -1 ) {
        x = atof(line);
    }
    return x;
}

// Function to read a list from standard input, split by space
char** LS(  ) {
    char* line = NULL;
    size_t len = 0;
    ssize_t read;
    char** list = NULL;
    while ( (read = getline(&line, &len, stdin)) != -1 ) {
        list = (char**)realloc(list, (len + 1) * sizeof(char*));
        list[len] = strtok(line, " ");
    }
    return list;
}

// Function to read a string from standard input
char* S(  ) {
    char* line = NULL;
    size_t len = 0;
    ssize_t read;
    while ( (read = getline(&line, &len, stdin)) != -1 ) {
        return line;
    }
    return NULL;
}

// Main function
int main(  ) {
    // Read input values
    int a, b, c, d;
    scanf("%d %d %d %d", &a, &b, &c, &d);

    // Calculate the maximum product of pairs of numbers
    int result = max(a*c, b*d, a*d, b*c);

    // Print the result
    printf("%d\n", result);

    // End of code
    return 0;
}

