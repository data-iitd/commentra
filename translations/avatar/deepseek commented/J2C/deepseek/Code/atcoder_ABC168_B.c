#include <stdio.h>
#include <string.h>

int main() {
    int K;
    char S[1000]; // Assuming the maximum length of the string is 1000

    // Read an integer K from the user
    scanf("%d", &K);

    // Read a string S from the user
    scanf("%s", S);

    // Check if the length of the string S is less than or equal to K
    if (strlen(S) <= K) {
        // If true, print the string S as it is
        printf("%s\n", S);
    } else {
        // If false, truncate the string to the first K characters and append "..."
        for (int i = 0; i < K; i++) {
            printf("%c", S[i]);
        }
        printf("...\n");
    }

    return 0;
}
