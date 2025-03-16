
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main()
{
    char word[100];
    int uppercase = 0, lowercase = 0;
    printf("Enter a word: ");
    scanf("%s", word);

    for (int i = 0; i < strlen(word); i++)
    {
        if (isupper(word[i]))
        {
            uppercase++;
        }
        else
        {
            lowercase++;
        }
    }

    if (uppercase > lowercase)
    {
        for (int i = 0; i < strlen(word); i++)
        {
            word[i] = toupper(word[i]);
        }
    }
    else if (lowercase > uppercase)
    {
        for (int i = 0; i < strlen(word); i++)
        {
            word[i] = tolower(word[i]);
        }
    }

    printf("The word is: %s\n", word);

    return 0;
}

