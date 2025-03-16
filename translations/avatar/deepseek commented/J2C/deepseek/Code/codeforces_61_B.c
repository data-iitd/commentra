#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main() {
    char word1[100], word2[100], word3[100];
    char perm1[200], perm2[200], perm3[200], perm4[200], perm5[200], perm6[200];
    char testCase[200];
    int students;

    // Read and process the three input words
    fgets(word1, sizeof(word1), stdin);
    word1[strcspn(word1, "\n")] = 0; // Remove newline character
    fgets(word2, sizeof(word2), stdin);
    word2[strcspn(word2, "\n")] = 0; // Remove newline character
    fgets(word3, sizeof(word3), stdin);
    word3[strcspn(word3, "\n")] = 0; // Remove newline character

    // Convert words to lowercase and remove non-alphabetic characters
    for (int i = 0; word1[i]; i++) {
        word1[i] = tolower(word1[i]);
        if (!isalpha(word1[i])) {
            word1[i] = '\0';
        }
    }
    for (int i = 0; word2[i]; i++) {
        word2[i] = tolower(word2[i]);
        if (!isalpha(word2[i])) {
            word2[i] = '\0';
        }
    }
    for (int i = 0; word3[i]; i++) {
        word3[i] = tolower(word3[i]);
        if (!isalpha(word3[i])) {
            word3[i] = '\0';
        }
    }

    // Generate all possible permutations of the three words
    strcpy(perm1, strcat(strcat(word1, word2), word3));
    strcpy(perm2, strcat(strcat(word1, word3), word2));
    strcpy(perm3, strcat(strcat(word2, word1), word3));
    strcpy(perm4, strcat(strcat(word2, word3), word1));
    strcpy(perm5, strcat(strcat(word3, word2), word1));
    strcpy(perm6, strcat(strcat(word3, word1), word2));

    // Read the number of test cases
    scanf("%d", &students);
    getchar(); // Consume the newline character after the integer input

    // Process each test case
    for (int i = 0; i < students; i++) {
        fgets(testCase, sizeof(testCase), stdin);
        testCase[strcspn(testCase, "\n")] = 0; // Remove newline character

        // Convert test case to lowercase and remove non-alphabetic characters
        for (int j = 0; testCase[j]; j++) {
            testCase[j] = tolower(testCase[j]);
            if (!isalpha(testCase[j])) {
                testCase[j] = '\0';
            }
        }

        // Check if the test case matches any of the generated permutations
        if (strcmp(testCase, perm1) == 0 || strcmp(testCase, perm2) == 0 || strcmp(testCase, perm3) == 0 ||
            strcmp(testCase, perm4) == 0 || strcmp(testCase, perm5) == 0 || strcmp(testCase, perm6) == 0) {
            printf("ACC\n"); // Print "ACC" if a match is found
        } else {
            printf("WA\n"); // Print "WA" if no match is found
        }
    }

