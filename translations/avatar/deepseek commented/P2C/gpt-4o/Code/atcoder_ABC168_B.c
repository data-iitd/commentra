#include <stdio.h>
#include <string.h>

#define MAX_LENGTH 1000 // Define a maximum length for the input string

char* main_function(int K, char* S) {
    static char result[MAX_LENGTH]; // Static array to hold the result

    // Check if the length of S is less than or equal to K
    if (strlen(S) <= K) {
        // If the length of S is less than or equal to K, return S as it is
        strcpy(result, S);
    } else {
        // If the length of S is greater than K, return the first K characters of S followed by '...'
        strncpy(result, S, K);
        result[K] = '\0'; // Null-terminate the string
        strcat(result, "..."); // Append '...'
    }
    return result;
}

int main() {
    int K;
    char S[MAX_LENGTH];

    // Read the value of K from the user
    scanf("%d", &K);
    // Read the string S from the user
    scanf("%s", S);

    // Print the result of the main function
    printf("%s\n", main_function(K, S));

    return 0;
}

// <END-OF-CODE>
