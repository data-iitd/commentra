

#include <stdio.h>
#include <string.h>

int main() {

    // Read the integer K from the standard input
    int K;
    scanf("%d", &K);

    // Read a string S from the standard input
    char S[1000];
    scanf("%s", S);

    // Check if the length of the string S is less than or equal to K
    if (strlen(S) <= K) {

        // If the condition is true, return the string S
        return printf("%s\n", S);

    }

    // If the condition is false, return a slice of the string S
    // from the beginning to the index K, followed by three dots '...'
    return printf("%.*s...\n", K, S);

}

