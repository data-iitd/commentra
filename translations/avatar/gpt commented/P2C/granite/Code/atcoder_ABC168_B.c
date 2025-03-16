
#include <stdio.h>
#include <string.h>

char* main() {
    // Read an integer input K from the user
    int K;
    scanf("%d", &K);
    
    // Read a string input S from the user
    char S[100];
    scanf("%s", S);
    
    // Check if the length of the string S is less than or equal to K
    if (strlen(S) <= K) {
        // If true, return the original string S
        return S;
    }
    
    // If the length of S is greater than K, return the first K characters followed by '...'
    char* result = (char*)malloc(K + 4);
    strncpy(result, S, K);
    strcpy(result + K, "...");
    return result;
}

// Entry point of the program
int main() {
    // Call the main function and print its result
    printf("%s\n", main());
    return 0;
}
