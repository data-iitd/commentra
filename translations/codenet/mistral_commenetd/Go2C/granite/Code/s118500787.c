
#include <stdio.h>
#include <string.h>

int main() {
    // Initialize two empty strings S and T
    char S[100001], T[100001];
    scanf("%s", S);
    scanf("%s", T);

    // Initialize max as 0
    int max = 0;

    // Loop through all possible substrings of S with length equal to T
    for (int i = 0; i <= strlen(S) - strlen(T); i++) {
        // Initialize a counter c for the number of matching characters between S[i:i+strlen(T)] and T
        int c = 0;

        // Check character by character for matching characters
        for (int j = 0; j < strlen(T); j++) {
            // If current characters match, increment counter c
            if (S[i+j] == T[j]) {
                c++;
            }
        }

        // If current substring has more matching characters than the current max, update max
        if (max < c) {
            max = c;
        }
    }

    // Print the length of the shortest substring of S that matches T with all characters
    printf("%d\n", strlen(T) - max);

    return 0;
}

// 