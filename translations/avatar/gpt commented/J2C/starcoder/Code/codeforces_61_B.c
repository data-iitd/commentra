#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main()
{
    char word1[100], word2[100], word3[100], testCase[100];
    scanf("%s %s %s", word1, word2, word3);
    int students;
    scanf("%d", &students);
    getchar();
    for (int i = 0; i < students; i++)
    {
        scanf("%s", testCase);
        if (strcmp(testCase, word1 + word2 + word3) == 0 || strcmp(testCase, word1 + word3 + word2) == 0 || strcmp(testCase, word2 + word1 + word3) == 0 || strcmp(testCase, word2 + word3 + word1) == 0 || strcmp(testCase, word3 + word2 + word1) == 0 || strcmp(testCase, word3 + word1 + word2) == 0)
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

