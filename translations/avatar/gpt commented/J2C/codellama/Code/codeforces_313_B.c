#include <stdio.h> 
#include <string.h> 

int main() { 
    // Create a BufferedReader to read input from the standard input stream
    FILE *br = stdin; 
    
    // Create a PrintWriter to output results to the standard output stream
    FILE *pw = stdout; 
    
    // Create an instance of the Fast class to process the input
    Fast f; 
    
    // Call the solution method to handle the input and produce output
    f.sol(br, pw); 
    
    // Close the PrintWriter to flush the output
    fclose(pw); 
} 

class Fast { 
    public void sol(FILE *br, FILE *pw) { 
        // Read the first line of input and tokenize it to get the string
        char s[100000]; 
        fgets(s, 100000, br); 
        char *token = strtok(s, " "); 
        char *s = token; 
        
        // Initialize a cumulative array to count consecutive characters
        int cum[100000]; 
        cum[0] = cum[strlen(s)] = 0; 
        
        // Fill the cumulative array with counts of consecutive characters
        for (int i = 1; i < strlen(s); i++) { 
            if (s[i] == s[i - 1]) 
                cum[i] = cum[i - 1] + 1; // Increment count if the current character is the same as the previous
            else 
                cum[i] = cum[i - 1]; // Carry forward the previous count if different
        } 
        
        // Read the number of queries from the input
        fgets(s, 100000, br); 
        token = strtok(s, " "); 
        int q = atoi(token); 
        
        // Process each query
        while (q-- != 0) { 
            // Read the range for the query
            fgets(s, 100000, br); 
            token = strtok(s, " "); 
            int l = atoi(token), r = atoi(token) - 1; 
            
            // Calculate and print the result for the current query
            fprintf(pw, "%d\n", cum[r] - cum[l - 1]); 
        } 
    } 
}

