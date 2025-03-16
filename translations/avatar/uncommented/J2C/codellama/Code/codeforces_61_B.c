
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main()
{
    char word1[100], word2[100], word3[100], perm1[100], perm2[100], perm3[100], perm4[100], perm5[100], perm6[100];
    int students;
    scanf("%s %s %s", word1, word2, word3);
    sprintf(perm1, "%s%s%s", word1, word2, word3);
    sprintf(perm2, "%s%s%s", word1, word3, word2);
    sprintf(perm3, "%s%s%s", word2, word1, word3);
    sprintf(perm4, "%s%s%s", word2, word3, word1);
    sprintf(perm5, "%s%s%s", word3, word2, word1);
    sprintf(perm6, "%s%s%s", word3, word1, word2);
    scanf("%d", &students);
    getchar();
    for (int i = 0; i < students; i++)
    {
        char testCase[100];
        scanf("%s", testCase);
        if (strcmp(testCase, perm1) == 0 || strcmp(testCase, perm2) == 0 || strcmp(testCase, perm3) == 0 || strcmp(testCase, perm4) == 0 || strcmp(testCase, perm5) == 0 || strcmp(testCase, perm6) == 0)
        {
            printf("ACC\n");
        }
        else
        {
            printf("WA\n");
        }
    }
    return 0;
}

