#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 

int main() { 
    // Create a buffer to read input from the standard input stream
    char buffer[1000000]; 
    
    // Read the first line of input and convert it to a character array
    fgets(buffer, 1000000, stdin); 
    char* arr = buffer; 
    
    // Get the length of the character array
    int N = strlen(arr); 
    
    // Initialize a HashSet to store unique strings (not used in this code)
    // HashSet<String> set = new HashSet<String>(); 
    
    // Read the number of queries K
    int K; 
    scanf("%d", &K); 
    
    // Initialize the result counter
    int res = 0; 
    
    // Loop through each query
    for (int k = 0; k < K; k++) { 
        // Read the input string for the current query
        char input[1000000]; 
        fgets(input, 1000000, stdin); 
        
        // Initialize counters for characters in the input string
        int a = 0; 
        int b = 0; 
        
        // Iterate through the character array
        for (int i = 0; i < N; i++) { 
            // Count occurrences of the first character of the input string
            if (arr[i] == input[0]) 
                a++; 
            // Count occurrences of the second character of the input string
            else if (arr[i] == input[1]) 
                b++; 
            // If neither character is found, update the result and reset counters
            else { 
                res += a < b ? a : b; 
                a = b = 0; 
            } 
        } 
        // Add the minimum count of the two characters to the result
        res += a < b ? a : b; 
    } 
    
    // Output the final result
    printf("%d\n", res); 
    
    return 0; 
} 
