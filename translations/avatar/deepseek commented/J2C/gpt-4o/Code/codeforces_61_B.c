#include <stdio.h>
#include <string.h>
#include <ctype.h>

void toLowerAlphaOnly(char *dest, const char *src) {
    while (*src) {
        if (isalpha((unsigned char)*src)) {
            *dest++ = tolower((unsigned char)*src);
        }
        src++;
    }
    *dest = '\0'; // Null-terminate the destination string
}

int main() {
    char word1[100], word2[100], word3[100];
    char perm1[300], perm2[300], perm3[300], perm4[300], perm5[300], perm6[300];
    char testCase[100];

    // Read and process the three input words
    fgets(word1, sizeof(word1), stdin);
    fgets(word2, sizeof(word2), stdin);
    fgets(word3, sizeof(word3), stdin);

    // Convert to lowercase and remove non-alphabetic characters
    char cleanWord1[100], cleanWord2[100], cleanWord3[100];
    toLowerAlphaOnly(cleanWord1, word1);
    toLowerAlphaOnly(cleanWord2, word2);
    toLowerAlphaOnly(cleanWord3, word3);

    // Generate all possible permutations of the three words
    sprintf(perm1, "%s%s%s", cleanWord1, cleanWord2, cleanWord3);
    sprintf(perm2, "%s%s%s", cleanWord1, cleanWord3, cleanWord2);
    sprintf(perm3, "%s%s%s", cleanWord2, cleanWord1, cleanWord3);
    sprintf(perm4, "%s%s%s", cleanWord2, cleanWord3, cleanWord1);
    sprintf(perm5, "%s%s%s", cleanWord3, cleanWord2, cleanWord1);
    sprintf(perm6, "%s%s%s", cleanWord3, cleanWord1, cleanWord2);

    // Read the number of test cases
    int students;
    scanf("%d\n", &students); // Read the integer and consume the newline character

    // Process each test case
    for (int i = 0; i < students; i++) {
        fgets(testCase, sizeof(testCase), stdin);
        char cleanTestCase[100];
        toLowerAlphaOnly(cleanTestCase, testCase);

        // Check if the test case matches any of the generated permutations
        if (strcmp(cleanTestCase, perm1) == 0 || strcmp(cleanTestCase, perm2) == 0 ||
            strcmp(cleanTestCase, perm3) == 0 || strcmp(cleanTestCase, perm4) == 0 ||
            strcmp(cleanTestCase, perm5) == 0 || strcmp(cleanTestCase, perm6) == 0) {
            printf("ACC\n"); // Print "ACC" if a match is found
        } else {
            printf("WA\n"); // Print "WA" if no match is found
        }
    }

    return 0;
}

// <END-OF-CODE>
