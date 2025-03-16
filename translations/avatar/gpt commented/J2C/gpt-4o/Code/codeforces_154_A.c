#include <stdio.h>
#include <string.h>

int main() {
    // Create a buffer to read the input string
    char arr[100001]; // Assuming the maximum length of the input string is 100000
    fgets(arr, sizeof(arr), stdin);
    
    // Get the length of the character array
    int N = strlen(arr) - 1; // Subtract 1 to ignore the newline character
    
    // Read the number of queries K
    int K;
    scanf("%d\n", &K); // Read K and consume the newline character
    
    // Initialize the result counter
    int res = 0;
    
    // Loop through each query
    for (int k = 0; k < K; k++) {
        // Read the input string for the current query
        char input[3]; // Assuming input will be exactly 2 characters + null terminator
        fgets(input, sizeof(input), stdin);
        
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
                res += (a < b) ? a : b; // Add the minimum of a and b to the result
                a = b = 0; // Reset counters
            }
        }
        // Add the minimum count of the two characters to the result
        res += (a < b) ? a : b;
    }
    
    // Output the final result
    printf("%d\n", res);
    
    return 0;
}

// <END-OF-CODE>
