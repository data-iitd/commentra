

#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {
    char word1[101], word2[101], word3[101], testCase[101];
    char perm1[303], perm2[303], perm3[303], perm4[303], perm5[303], perm6[303];
    int students, i, j;

    // Read and process the three input words
    scanf("%s", word1);
    for (i = 0; word1[i]!= '\0'; i++) {
        word1[i] = tolower(word1[i]);
    }
    scanf("%s", word2);
    for (i = 0; word2[i]!= '\0'; i++) {
        word2[i] = tolower(word2[i]);
    }
    scanf("%s", word3);
    for (i = 0; word3[i]!= '\0'; i++) {
        word3[i] = tolower(word3[i]);
    }

    // Generate all possible permutations of the three words
    strcpy(perm1, word1);
    strcat(perm1, word2);
    strcat(perm1, word3);
    strcpy(perm2, word1);
    strcat(perm2, word3);
    strcat(perm2, word2);
    strcpy(perm3, word2);
    strcat(perm3, word1);
    strcat(perm3, word3);
    strcpy(perm4, word2);
    strcat(perm4, word3);
    strcat(perm4, word1);
    strcpy(perm5, word3);
    strcat(perm5, word2);
    strcat(perm5, word1);
    strcpy(perm6, word3);
    strcat(perm6, word1);
    strcat(perm6, word2);

    // Read the number of test cases
    scanf("%d", &students);
    getchar(); // Consume the newline character after the integer input

    // Process each test case
    for (i = 0; i < students; i++) {
        scanf("%s", testCase);
        for (j = 0; testCase[j]!= '\0'; j++) {
            testCase[j] = tolower(testCase[j]);
        }
        if (strcmp(testCase, perm1) == 0 || strcmp(testCase, perm2) == 0 || strcmp(testCase, perm3) == 0 ||
            strcmp(testCase, perm4) == 0 || strcmp(testCase, perm5) == 0 || strcmp(testCase, perm6) == 0) {
            printf("ACC\n"); // Print "ACC" if a match is found
        } else {
            printf("WA\n"); // Print "WA" if no match is found
        }
    }

    return 0;
}
