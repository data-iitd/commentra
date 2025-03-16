#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main() {
    char word1[100], word2[100], word3[100];
    fgets(word1, sizeof(word1), stdin);
    fgets(word2, sizeof(word2), stdin);
    fgets(word3, sizeof(word3), stdin);

    // Remove non-alphabetic characters and convert to lowercase
    word1[strcspn(word1, "\n")] = '\0';
    word2[strcspn(word2, "\n")] = '\0';
    word3[strcspn(word3, "\n")] = '\0';

    for (int i = 0; word1[i]; i++) {
        word1[i] = tolower(word1[i]);
    }
    for (int i = 0; word2[i]; i++) {
        word2[i] = tolower(word2[i]);
    }
    for (int i = 0; word3[i]; i++) {
        word3[i] = tolower(word3[i]);
    }

    char perm1[300], perm2[300], perm3[300], perm4[300], perm5[300], perm6[300];
    snprintf(perm1, sizeof(perm1), "%s%s%s", word1, word2, word3);
    snprintf(perm2, sizeof(perm2), "%s%s%s", word1, word3, word2);
    snprintf(perm3, sizeof(perm3), "%s%s%s", word2, word1, word3);
    snprintf(perm4, sizeof(perm4), "%s%s%s", word2, word3, word1);
    snprintf(perm5, sizeof(perm5), "%s%s%s", word3, word2, word1);
    snprintf(perm6, sizeof(perm6), "%s%s%s", word3, word1, word2);

    int students;
    scanf("%d", &students);
    getchar(); // Consume the newline character

    for (int i = 0; i < students; i++) {
        char testCase[100];
        fgets(testCase, sizeof(testCase), stdin);

        // Remove non-alphabetic characters and convert to lowercase
        testCase[strcspn(testCase, "\n")] = '\0';

        for (int j = 0; testCase[j]; j++) {
            testCase[j] = tolower(testCase[j]);
        }

        if (strcmp(testCase, perm1) == 0 || strcmp(testCase, perm2) == 0 ||
            strcmp(testCase, perm3) == 0 || strcmp(testCase, perm4) == 0 ||
            strcmp(testCase, perm5) == 0 || strcmp(testCase, perm6) == 0) {
            printf("ACC\n");
        } else {
            printf("WA\n");
        }
    }

    return 0;
}
