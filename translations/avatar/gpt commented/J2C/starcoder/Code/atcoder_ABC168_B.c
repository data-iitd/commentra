#include <stdio.h>
#include <stdlib.h>

int main() {
    // Declare a variable to store the maximum length of the string to display
    int K;
    
    // Read an integer K from the user, which represents the maximum length of the string to display
    scanf("%d", &K);
    
    // Declare a variable to store the string S
    char S[10000];
    
    // Read a string S from the user
    scanf("%s", S);
    
    // Check if the length of the string S is less than or equal to K
    if (strlen(S) <= K) {
        // If true, print the string S as it is
        printf("%s", S);
    } else {
        // If false, print the first K characters of S followed by "..."
        printf("%.*s...", K, S);
    }
    
    // Return from main
    return 0;
}

