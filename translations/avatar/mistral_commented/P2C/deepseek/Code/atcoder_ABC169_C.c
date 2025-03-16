#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

#define MAX_RECURSION_LIMIT 1000000

// Set the recursion limit for the function call stack
// This is necessary to prevent a "RecursionError" when dealing with large inputs
void set_recursion_limit() {
    // Set the recursion limit to a large value
    setrecursionlimit(MAX_RECURSION_LIMIT);
}

// Define a debug function to print debug messages
// This function is used only when running the program in an IDE or terminal
#define DEBUG_MODE
#ifdef DEBUG_MODE
#define dbg(args...) fprintf(stderr, args)
#else
#define dbg(args...)
#endif

// Define the input function to read input from standard input
char *input() {
    static char buffer[1024];
    return fgets(buffer, sizeof(buffer), stdin);
}

// Define a function to read multiple integers as a list
int* LMIIS() {
    static char buffer[1024];
    fgets(buffer, sizeof(buffer), stdin);
    int *numbers = (int*)malloc(sizeof(int) * 100); // Assuming a maximum of 100 numbers
    char *token = strtok(buffer, " ");
    int count = 0;
    while (token != NULL) {
        numbers[count++] = atoi(token);
        token = strtok(NULL, " ");
    }
    return numbers;
}

// Define input reading functions for single integer and string
int II() {
    char buffer[1024];
    fgets(buffer, sizeof(buffer), stdin);
    return atoi(buffer);
}

const int P = 1000000007;
const int INF = 1000000001;

// Main function to start the program
int main() {
    set_recursion_limit();

    char sa[10], sb[10];
    int a, b;

    fgets(sa, sizeof(sa), stdin);
    sa[strcspn(sa, "\n")] = 0; // Remove newline character
    fgets(sb, sizeof(sb), stdin);
    sb[strcspn(sb, "\n")] = 0; // Remove newline character

    a = atoi(sa);
    b = (int)(atof(sb) * 100 + 0.1);

    printf("%d\n", a * b / 100);

    return 0;
}
