#include <stdio.h>
#include <string.h>

int main()
{
    char word1[100], word2[100], word3[100], testCase[100];
    scanf("%s", word1);
    scanf("%s", word2);
    scanf("%s", word3);
    scanf("%d", &students);
    scanf("\n");
    for (int i = 0; i < students; i++)
    {
        scanf("%s", testCase);
        if (strcmp(testCase, word1) == 0 || strcmp(testCase, word2) == 0 || strcmp(testCase, word3) == 0 || strcmp(testCase, word1 + word2) == 0 || strcmp(testCase, word1 + word3) == 0 || strcmp(testCase, word2 + word3) == 0 || strcmp(testCase, word1 + word2 + word3) == 0 || strcmp(testCase, word2 + word1 + word3) == 0 || strcmp(testCase, word3 + word2 + word1) == 0 || strcmp(testCase, word3 + word1 + word2) == 0)
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
