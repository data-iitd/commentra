
#include <stdio.h>
#include <string.h>

int main() {
    char word1[100], word2[100], word3[100];
    char perm1[300], perm2[300], perm3[300], perm4[300], perm5[300], perm6[300];
    int students;
    scanf("%s %s %s", word1, word2, word3);
    scanf("%d", &students);
    for (int i = 0; i < students; i++) {
        char testCase[100];
        scanf("%s", testCase);
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
        if (strcmp(testCase, perm1) == 0 || strcmp(testCase, perm2) == 0 || strcmp(testCase, perm3) == 0 || strcmp(testCase, perm4) == 0 || strcmp(testCase, perm5) == 0 || strcmp(testCase, perm6) == 0) {
            printf("ACC\n");
        } else {
            printf("WA\n");
        }
    }
    return 0;
}

