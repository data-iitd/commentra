

#include <stdio.h>
#include <string.h>

int main() {
    // Create a variable to store the length of the string
    int length;
    
    // Read an integer K from the user
    int K;
    scanf("%d", &K);
    
    // Read a string S from the user
    char S[100];
    scanf("%s", S);
    
    // Get the length of the string S
    length = strlen(S);
    
    // Check if the length of the string S is less than or equal to K
    if (length <= K) {
        // If true, print the string S as it is
        printf("%s\n", S);
    } else {
        // If false, truncate the string to the first K characters and append "..."
        S[K] = '\0';
        printf("%s...\n", S);
    }
    
    return 0;
}
