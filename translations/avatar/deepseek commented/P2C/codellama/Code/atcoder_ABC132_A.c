
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char S[100];
    int i, j, count[26] = {0};
    printf("Enter a string: ");
    scanf("%s", S);
    for (i = 0; S[i] != '\0'; i++)
    {
        count[S[i] - 'a']++;
    }
    for (i = 0; i < 26; i++)
    {
        if (count[i] != 2)
        {
            printf("No");
            return 0;
        }
    }
    printf("Yes");
    return 0;
}

