#include <stdio.h>
#include <string.h>

int main() {
    int K;
    char S[1000];  // Assuming the maximum length of the string S is 1000

    // Read an integer input K from the user
    scanf("%d", &K);
    
    // Read a string input S from the user
    scanf("%s", S);
    
    // Check if the length of the string S is less than or equal to K
    if (strlen(S) <= K) {
        // If true, return the original string S
        printf("%s\n", S);
    } else {
        // If the length of S is greater than K, return the first K characters followed by '...'
        for (int i = 0; i < K; i++) {
            printf("%c", S[i]);
        }
        printf("...\n");
    }

    return 0;
}
