
#include <stdio.h> 
#include <string.h> 
#include <math.h> 
#include <stdlib.h> 

int main() { 
    // Create a character array to store the input string
    char arr[100001]; 
    // Read the input string and store it in the character array
    scanf("%s", arr); 
    // Get the length of the input string
    int N = strlen(arr); 
    // Initialize the result counter
    int res = 0; 
    // Read the number of queries K
    int K; 
    scanf("%d", &K); 
    // Loop through each query
    for (int k = 0; k < K; k++) { 
        // Create a character array to store the current query string
        char input[3]; 
        // Read the current query string and store it in the character array
        scanf("%s", input); 
        // Initialize counters for characters in the current query string
        int a = 0; 
        int b = 0; 
        // Iterate through the character array
        for (int i = 0; i < N; i++) { 
            // Count occurrences of the first character of the current query string
            if (arr[i] == input[0]) 
                a++; 
            // Count occurrences of the second character of the current query string
            else if (arr[i] == input[1]) 
                b++; 
            // If neither character is found, update the result and reset counters
            else { 
                res += (a < b? a : b); 
                a = b = 0; 
            } 
        } 
        // Add the minimum count of the two characters to the result
        res += (a < b? a : b); 
    } 
    // Output the final result
    printf("%d\n", res); 
    return 0; 
}
