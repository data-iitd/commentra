
#include <stdio.h> // Include the standard input/output library
#include <string.h> // Include the string library

int main() {
    // Declare and initialize an integer variable K to store the maximum length of the string to display
    int K;
    scanf("%d", &K); // Read an integer K from the user using scanf
    
    // Declare and initialize a character array variable S to store the string input by the user
    char S[100];
    scanf("%s", S); // Read a string S from the user using scanf
    
    // Check if the length of the string S is less than or equal to K
    if (strlen(S) <= K) {
        // If true, print the string S as it is using printf
        printf("%s\n", S);
    } else {
        // If false, print the first K characters of S followed by "..." using printf
        printf("%.*s...\n", K, S);
    }
    
    // Return 0 to indicate successful program execution
    return 0;
}
