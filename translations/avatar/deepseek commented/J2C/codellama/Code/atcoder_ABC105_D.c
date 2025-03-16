#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

// Initialize input and output streams
FILE *inputStream = stdin;
FILE *outputStream = stdout;

// InputReader class to read input efficiently
typedef struct InputReader {
    FILE *br;
    char *st;
} InputReader;

// Create an instance of InputReader
InputReader in = {inputStream, NULL};

// TaskD class containing the solve method
typedef struct TaskD {
    void solve(int testNumber, InputReader *in, FILE *out);
} TaskD;

// Create an instance of TaskD
TaskD solver = {NULL};

// Read the next string from the input
char *nextString(InputReader *in) {
    while (!in->st) {
        in->st = fgets(in->st, 1000, in->br);
    }
    return in->st;
}

// Read the next integer from the input
int nextInt(InputReader *in) {
    return atoi(nextString(in));
}

// Read the next array of integers from the input
int *nextIntArray(InputReader *in, int n) {
    int *res = (int *)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        res[i] = nextInt(in);
    }
    return res;
}

// Solve the problem
void solve(int testNumber, InputReader *in, FILE *out) {
    // Read the number of elements and the modulo value
    int n = nextInt(in);
    int m = nextInt(in);
    
    // Read the array of elements
    int *a = nextIntArray(in, n);
    
    // HashMap to store the frequency of remainders
    int *dp = (int *)malloc(m * sizeof(int));
    
    // Initialize the answer and base variable
    long ans = 0;
    int base = 0;
    
    // Iterate through the array to calculate the answer
    for (int i = 0; i < n; i++) {
        // Update the base variable
        base = (base - a[i] % m + m) % m;
        
        // Update the frequency of remainders in the HashMap
        dp[base]++;
        
        // Add the frequency of the current remainder to the answer
        ans += dp[base];
    }
    
    // Print the final answer
    fprintf(out, "%ld\n", ans);
}

// Main function
int main() {
    // Create an instance of TaskD and solve the problem
    solver.solve(1, &in, outputStream);
    
    // Close the output stream
    fclose(outputStream);
    
    return 0;
}

// End of code
