#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 
#include <stdbool.h> 

// Number of characters to generate
int N; 
// Modulus value for large number calculations
long MOD = 1000000007L; 
// Possible tokens (characters) to use
char* TOKENS[] = { "A", "C", "G", "T" }; 
// Memoization array to store computed results
long** memo; 

// Constructor to initialize the class
void init() { 
    // Create a scanner to read input
    FILE* in = fopen("input.txt", "r"); 
    // Read the number of characters to generate
    fscanf(in, "%d", &N); 
    // Close the scanner
    fclose(in); 
    // Initialize the memoization array
    memo = (long**) malloc((N + 1) * sizeof(long*)); 
    for (int i = 0; i < N + 1; ++i) { 
        // Initialize each entry in the memoization array with a new array
        memo[i] = (long*) malloc(4 * sizeof(long)); 
        for (int j = 0; j < 4; ++j) { 
            memo[i][j] = -1; 
        } 
    } 
} 

// Method to calculate the total valid sequences
long calc() { 
    // Start the depth-first search with the initial state
    return dfs(0, "TTT"); 
} 

// Method to check if the last 4 characters are valid
bool isOK(char* last4) { 
    // Check if the last 4 characters contain "AGC"
    if (strstr(last4, "AGC") != NULL) { 
        return false; 
    } 
    // Check all permutations of the last 4 characters
    for (int i = 0; i < 3; ++i) { 
        char* vals = (char*) malloc(4 * sizeof(char)); 
        // Swap characters to create a new permutation
        vals[i] = last4[i + 1]; 
        vals[i + 1] = last4[i]; 
        char* s = (char*) malloc(4 * sizeof(char)); 
        strcpy(s, vals); 
        // Check if the new permutation contains "AGC"
        if (strstr(s, "AGC") != NULL) { 
            return false; 
        } 
    } 
    // If no invalid sequences found, return true
    return true; 
} 

// Depth-first search method to explore all possible sequences
long dfs(int current, char* last3) { 
    // Check if the result is already computed and stored in memo
    if (memo[current][0] != -1) { 
        return memo[current][0]; 
    } 
    // Base case: if the current length equals N, return 1 (valid sequence)
    if (current == N) { 
        return 1; 
    } 
    // Variable to accumulate the result
    long result = 0; 
    // Iterate through each possible token
    for (int i = 0; i < 4; ++i) { 
        // Check if adding the token to the last 3 characters is valid
        if (isOK(last3)) { 
            // Recursively call dfs for the next character
            result = (result + dfs(current + 1, last3 + TOKENS[i])) % MOD; 
        } 
    } 
    // Store the computed result in memoization array
    memo[current][0] = result; 
    return result; 
} 

// Main method to execute the program
int main() { 
    // Create an instance of Main class
    init(); 
    // Print the result of the calculation
    printf("%ld\n", calc()); 
    return 0; 
} 

