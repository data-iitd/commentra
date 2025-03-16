#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 
#include <math.h> 

// FastScanner class for efficient input handling
typedef struct FastScanner { 
    FILE *br; 
    char *st; 
} FastScanner; 

// Method to read the next token
char *next(FastScanner *in) { 
    // Read new line if no more tokens are available
    while (!in->st) { 
        in->st = fgets(in->st, 1000, in->br); 
    } 
    return strtok(in->st, " "); 
} 

// Method to read the next line
char *nextLine(FastScanner *in) { 
    char *str = ""; 
    str = fgets(str, 1000, in->br); 
    return str; 
} 

// Methods to read different data types
int nextByte(FastScanner *in) { return atoi(next(in)); } 
int nextShort(FastScanner *in) { return atoi(next(in)); } 
int nextInt(FastScanner *in) { return atoi(next(in)); } 
long nextLong(FastScanner *in) { return atol(next(in)); } 
double nextDouble(FastScanner *in) { return atof(next(in)); } 

int main() { 
    // Initialize FastScanner for efficient input reading
    FastScanner in = {stdin, NULL}; 
    // Create a Scanner object for standard input
    Scanner sc = {stdin, NULL}; 
    // Create a PrintWriter object for output
    PrintWriter o = {stdout, NULL}; 
    
    // Read the number of pairs (n) and the minimum score (s)
    int n = nextInt(&sc); 
    int s = nextInt(&sc); 
    
    // Initialize a variable to keep track of the maximum sum of pairs
    int max = 0; 
    
    // Loop through each pair of integers
    while (n-- > 0) { 
        // Read the two integers f and t
        int f = nextInt(&sc); 
        int t = nextInt(&sc); 
        // Update max if the sum of f and t is greater than the current max
        if (max < f + t) { 
            max = f + t; 
        } 
    } 
    
    // Print the maximum value between max and s
    printf("%d\n", max > s ? max : s); 
    // Close the PrintWriter
    fclose(o.fp); 
    return 0; 
} 

