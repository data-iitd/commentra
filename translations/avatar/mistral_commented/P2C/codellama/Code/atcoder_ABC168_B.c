
#include <stdio.h>
#include <string.h>

// Define the main function, taking no arguments
int main() {

    // Declare the integer K and the string S
    int K;
    char S[100];

    // Read the integer K from the standard input
    scanf("%d", &K);

    // Read a string S from the standard input
    scanf("%s", S);

    // Check if the length of the string S is less than or equal to K
    if (strlen(S) <= K) {

        // If the condition is true, return the string S
        return S;

    }

    // If the condition is false, return a slice of the string S
    // from the beginning to the index K, followed by three dots '...'
    return S[:K] + "...";

}

// Define the entry point of the script
if (__name__ == "__main__") {

    // Call the main function and print its result
    printf("%s", main());

}

