#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main() {
    char word1[100], word2[100], word3[100], perm1[300], perm2[300], perm3[300], perm4[300], perm5[300], perm6[300];
    char testCase[100];
    int students;

    // Read three words from the input, remove non-alphabetic characters, and convert them to lowercase
    fgets(word1, sizeof(word1), stdin);
    word1[strcspn(word1, "\n")] = 0; // Remove newline character
    for (int i = 0; word1[i]; i++) word1[i] = tolower(word1[i]);

    fgets(word2, sizeof(word2), stdin);
    word2[strcspn(word2, "\n")] = 0; // Remove newline character
    for (int i = 0; word2[i]; i++) word2[i] = tolower(word2[i]);

    fgets(word3, sizeof(word3), stdin);
    word3[strcspn(word3, "\n")] = 0; // Remove newline character
    for (int i = 0; word3[i]; i++) word3[i] = tolower(word3[i]);

    // Generate all possible permutations of the three words
    sprintf(perm1, "%s%s%s", word1, word2, word3);
    sprintf(perm2, "%s%s%s", word1, word3, word2);
    sprintf(perm3, "%s%s%s", word2, word1, word3);
    sprintf(perm4, "%s%s%s", word2, word3, word1);
    sprintf(perm5, "%s%s%s", word3, word2, word1);
    sprintf(perm6, "%s%s%s", word3, word1, word2);

    // Read the number of students (test cases)
    scanf("%d", &students);
    getchar(); // Consume the newline character after the integer input

    // Loop through each student's test case
    for (int i = 0; i < students; i++) {
        // Read the test case input, remove non-alphabetic characters, and convert to lowercase
        fgets(testCase, sizeof(testCase), stdin);
        testCase[strcspn(testCase, "\n")] = 0; // Remove newline character
        for (int j = 0; testCase[j]; j++) testCase[j] = tolower(testCase[j]);

        // Check if the test case matches any of the generated permutations
        if (strcmp(testCase, perm1) == 0 || strcmp(testCase, perm2) == 0 ||
            strcmp(testCase, perm3) == 0 || strcmp(testCase, perm4) == 0 ||
            strcmp(testCase, perm5) == 0 || strcmp(testCase, perm6) == 0) {
            // If it matches, print "ACC" (Accepted)
            printf("ACC\n");
        } else {
            // If it doesn't match, print "WA" (Wrong Answer)
            printf("WA\n");
        }
    }

    return 0;
}
