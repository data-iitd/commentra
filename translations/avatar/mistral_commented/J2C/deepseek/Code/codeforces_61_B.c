#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main() {
    char word1[100], word2[100], word3[100], testCase[100];
    int students;

    // Reading the first word from the user input
    fgets(word1, sizeof(word1), stdin);
    word1[strcspn(word1, "\n")] = 0; // Remove newline character
    for (int i = 0; word1[i]; i++) {
        word1[i] = tolower(word1[i]);
    }

    // Reading the second word from the user input
    fgets(word2, sizeof(word2), stdin);
    word2[strcspn(word2, "\n")] = 0; // Remove newline character
    for (int i = 0; word2[i]; i++) {
        word2[i] = tolower(word2[i]);
    }

    // Reading the third word from the user input
    fgets(word3, sizeof(word3), stdin);
    word3[strcspn(word3, "\n")] = 0; // Remove newline character
    for (int i = 0; word3[i]; i++) {
        word3[i] = tolower(word3[i]);
    }

    // Creating six permutations of the given words
    char perm1[300], perm2[300], perm3[300], perm4[300], perm5[300], perm6[300];
    sprintf(perm1, "%s%s%s", word1, word2, word3);
    sprintf(perm2, "%s%s%s", word1, word3, word2);
    sprintf(perm3, "%s%s%s", word2, word1, word3);
    sprintf(perm4, "%s%s%s", word2, word3, word1);
    sprintf(perm5, "%s%s%s", word3, word2, word1);
    sprintf(perm6, "%s%s%s", word3, word1, word2);

    // Reading the number of students
    scanf("%d", &students);
    getchar(); // Consume newline character left after reading an integer.

    // Looping through each student's test case
    for (int i = 0; i < students; i++) {
        // Reading a test case from the user input
        fgets(testCase, sizeof(testCase), stdin);
        testCase[strcspn(testCase, "\n")] = 0; // Remove newline character
        for (int j = 0; testCase[j]; j++) {
            testCase[j] = tolower(testCase[j]);
        }

        // Checking if the test case matches any of the permutations
        if (strcmp(testCase, perm1) == 0 || strcmp(testCase, perm2) == 0 || strcmp(testCase, perm3) == 0 ||
            strcmp(testCase, perm4) == 0 || strcmp(testCase, perm5) == 0 || strcmp(testCase, perm6) == 0) {
            // Printing 'ACC' if the test case matches any of the permutations
            printf("ACC\n");
        } else {
            // Printing 'WA' if the test case doesn't match any of the permutations
            printf("WA\n");
        }
    }

    return 0;
}
