
#include <stdio.h>
#include <string.h>

int main() {
    char word1[100], word2[100], word3[100], perm1[300], perm2[300], perm3[300], perm4[300], perm5[300], perm6[300], testCase[100];
    int students, i;

    // Reading the first word from the user input
    scanf("%s", word1);
    // This block of code reads a word from the user input and stores it in the 'word1' variable.

    // Reading the second word from the user input
    scanf("%s", word2);
    // This block of code reads a word from the user input and stores it in the 'word2' variable.

    // Reading the third word from the user input
    scanf("%s", word3);
    // This block of code reads a word from the user input and stores it in the 'word3' variable.

    // Creating six permutations of the given words
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

    // Reading the number of students
    scanf("%d", &students);
    // This block of code reads an integer value from the user input and stores it in the'students' variable.

    // Looping through each student's test case
    for (i = 0; i < students; i++) {
        // Reading a test case from the user input
        scanf("%s", testCase);
        // This block of code reads a word from the user input and stores it in the 'testCase' variable.

        // Checking if the test case matches any of the permutations
        if (strcmp(testCase, perm1) == 0 || strcmp(testCase, perm2) == 0 || strcmp(testCase, perm3) == 0 || strcmp(testCase, perm4) == 0 || strcmp(testCase, perm5) == 0 || strcmp(testCase, perm6) == 0) {
            // Printing 'ACC' if the test case matches any of the permutations
            printf("ACC\n");
        } else {
            // Printing 'WA' if the test case doesn't match any of the permutations
            printf("WA\n");
        }
    }

    return 0;
}
// Translate the above C code to Python and end with comment "