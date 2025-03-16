// Importing necessary libraries
#include <stdio.h>
#include <string.h>
#include <ctype.h>

// Function to clean and convert a string to lowercase
void cleanString(char *input, char *output) {
    int j = 0;
    for (int i = 0; input[i] != '\0'; i++) {
        if (isalpha(input[i])) {
            output[j++] = tolower(input[i]);
        }
    }
    output[j] = '\0'; // Null-terminate the cleaned string
}

int main() {
    // Declaring variables
    char word1[100], word2[100], word3[100];
    char perm1[300], perm2[300], perm3[300], perm4[300], perm5[300], perm6[300];
    int students;

    // Reading the first word from the user input
    fgets(word1, sizeof(word1), stdin);
    cleanString(word1, word1);

    // Reading the second word from the user input
    fgets(word2, sizeof(word2), stdin);
    cleanString(word2, word2);

    // Reading the third word from the user input
    fgets(word3, sizeof(word3), stdin);
    cleanString(word3, word3);

    // Creating six permutations of the given words
    sprintf(perm1, "%s%s%s", word1, word2, word3);
    sprintf(perm2, "%s%s%s", word1, word3, word2);
    sprintf(perm3, "%s%s%s", word2, word1, word3);
    sprintf(perm4, "%s%s%s", word2, word3, word1);
    sprintf(perm5, "%s%s%s", word3, word2, word1);
    sprintf(perm6, "%s%s%s", word3, word1, word2);

    // Reading the number of students
    scanf("%d\n", &students); // The '\n' consumes the newline character

    // Looping through each student's test case
    for (int i = 0; i < students; i++) {
        char testCase[100];
        fgets(testCase, sizeof(testCase), stdin);
        cleanString(testCase, testCase);

        // Checking if the test case matches any of the permutations
        if (strcmp(testCase, perm1) == 0 || strcmp(testCase, perm2) == 0 || 
            strcmp(testCase, perm3) == 0 || strcmp(testCase, perm4) == 0 || 
            strcmp(testCase, perm5) == 0 || strcmp(testCase, perm6) == 0) {
            // Printing 'ACC' if the test case matches any of the permutations
            printf("ACC\n");
        } else {
            // Printing 'WA' if the test case doesn't match any of the permutations
            printf("WA\n");
        }
    }

    return 0;
}

// <END-OF-CODE>
