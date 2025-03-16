#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 

// Define the InputReader class to read input from the input stream
typedef struct InputReader { 
    FILE *reader; 
    char *tokenizer; 
} InputReader; 

// Define the Task class to solve the problem
typedef struct Task { 
    void (*solve)(InputReader *in, FILE *out); 
} Task; 

// Method to read the next token from input
char *next(InputReader *in) { 
    // Read a new line if the tokenizer is empty
    while (in->tokenizer == NULL || strlen(in->tokenizer) == 0) { 
        in->tokenizer = malloc(1000000 * sizeof(char)); 
        fgets(in->tokenizer, 1000000, in->reader); 
    } 
    char *token = strtok(in->tokenizer, " "); 
    in->tokenizer = NULL; 
    return token; 
} 

// Method to read the next integer from input
int nextInt(InputReader *in) { 
    return atoi(next(in)); 
} 

// Method to read the next long from input
long nextLong(InputReader *in) { 
    return atol(next(in)); 
} 

// Method to read the next double from input
double nextDouble(InputReader *in) { 
    return atof(next(in)); 
} 

// Method to read the next line from input
char *nextLine(InputReader *in) { 
    char *str = malloc(1000000 * sizeof(char)); 
    fgets(str, 1000000, in->reader); 
    return str; 
} 

// Method to solve the problem
void solve(InputReader *in, FILE *out) { 
    // Read the number of elements
    int n = nextInt(in); 
    
    // Initialize an array to count occurrences of each index (up to 1000)
    int array[1001]; 
    memset(array, 0, sizeof(array)); 
    
    // Read n integers and count their occurrences
    for (int i = 0; i < n; i++) { 
        int index = nextInt(in); 
        array[index]++; 
    } 
    
    // Determine the maximum count of any index
    int countMax = -1; 
    for (int i = 1; i < 1001; i++) { 
        if (countMax < array[i]) 
            countMax = array[i]; 
    } 
    
    // Check if the maximum count is within allowed limits based on n being even or odd
    if (n % 2 == 0) { 
        // For even n, check if the maximum count is less than or equal to n/2
        if (countMax <= n / 2) { 
            fprintf(out, "YES\n"); 
        } else { 
            fprintf(out, "NO\n"); 
        } 
    } else { 
        // For odd n, check if the maximum count is less than or equal to n/2 + 1
        if (countMax <= n / 2 + 1) { 
            fprintf(out, "YES\n"); 
        } else { 
            fprintf(out, "NO\n"); 
        } 
    } 
} 

// Main method to initialize the InputReader and Task classes and call the solve method
int main() { 
    // Set up input and output streams
    FILE *inputStream = stdin; 
    FILE *outputStream = stdout; 
    
    // Create an InputReader to read input from the input stream
    InputReader in = { inputStream, NULL }; 
    
    // Create a Task class to solve the problem
    Task solver = { solve }; 
    
    // Call the solve method to process the input and produce output
    solver.solve(&in, outputStream); 
    
    // Close the output stream to flush and release resources
    fclose(outputStream); 
    
    return 0; 
} 

// End of code
