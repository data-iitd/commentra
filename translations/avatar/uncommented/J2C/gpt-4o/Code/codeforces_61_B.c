#include <stdio.h>
#include <string.h>
#include <ctype.h>

void toLowerAlphaOnly(char *input, char *output) {
    int j = 0;
    for (int i = 0; input[i] != '\0'; i++) {
        if (isalpha(input[i])) {
            output[j++] = tolower(input[i]);
        }
    }
    output[j] = '\0'; // Null-terminate the output string
}

int main() {
    char word1[100], word2[100], word3[100];
    char perm1[300], perm2[300], perm3[300], perm4[300], perm5[300], perm6[300];
    char testCase[100];
    int students;

    // Read and process the three words
    fgets(word1, sizeof(word1), stdin);
    fgets(word2, sizeof(word2), stdin);
    fgets(word3, sizeof(word3), stdin);

    char cleanWord1[100], cleanWord2[100], cleanWord3[100];
    toLowerAlphaOnly(word1, cleanWord1);
    toLowerAlphaOnly(word2, cleanWord2);
    toLowerAlphaOnly(word3, cleanWord3);

    // Create permutations
    sprintf(perm1, "%s%s%s", cleanWord1, cleanWord2, cleanWord3);
    sprintf(perm2, "%s%s%s", cleanWord1, cleanWord3, cleanWord2);
    sprintf(perm3, "%s%s%s", cleanWord2, cleanWord1, cleanWord3);
    sprintf(perm4, "%s%s%s", cleanWord2, cleanWord3, cleanWord1);
    sprintf(perm5, "%s%s%s", cleanWord3, cleanWord2, cleanWord1);
    sprintf(perm6, "%s%s%s", cleanWord3, cleanWord1, cleanWord2);

    // Read number of students
    scanf("%d\n", &students);

    // Process each test case
    for (int i = 0; i < students; i++) {
        fgets(testCase, sizeof(testCase), stdin);
        char cleanTestCase[100];
        toLowerAlphaOnly(testCase, cleanTestCase);

        if (strcmp(cleanTestCase, perm1) == 0 || strcmp(cleanTestCase, perm2) == 0 ||
            strcmp(cleanTestCase, perm3) == 0 || strcmp(cleanTestCase, perm4) == 0 ||
            strcmp(cleanTestCase, perm5) == 0 || strcmp(cleanTestCase, perm6) == 0) {
            printf("ACC\n");
        } else {
            printf("WA\n");
        }
    }

    return 0;
}

// <END-OF-CODE>
