#include <stdio.h>
#include <string.h>

int main() {
    // Declare variables to store the value of K and the string S
    int K;
    char S[1000];

    // Read the value of K from the user
    scanf("%d", &K);
    // Read the string S from the user
    scanf("%s", S);

    // Check if the length of S is less than or equal to K
    if (strlen(S) <= K) {
        // If the length of S is less than or equal to K, print S as it is
        printf("%s\n", S);
    } else {
        // If the length of S is greater than K, print the first K characters of S followed by '...'
        for (int i = 0; i < K; i++) {
            printf("%c", S[i]);
        }
        printf("...\n");
    }

    return 0;
}

