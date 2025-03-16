#include <stdio.h>
#include <string.h>

int main()
{
    char s[100];
    char res[100];
    int i, j;
    char punctuation[] = {',', '.', '!', '?'};

    printf("Enter a string: ");
    scanf("%s", s);

    j = 0;
    for (i = 0; i < strlen(s); i++)
    {
        if (i >= 1)
        {
            if (s[i] == ' ')
            {
                if (res[j - 1] != ' ')
                {
                    res[j++] = s[i];
                }
                else
                {
                    continue;
                }
            }
            else
            {
                if (s[i] == punctuation[0] || s[i] == punctuation[1] || s[i] == punctuation[2] || s[i] == punctuation[3])
                {
                    if (res[j - 1] == ' ')
                    {
                        res[j - 1] = '\0';
                    }
                    res[j++] = s[i];
                    res[j++] = ' ';
                }
                else
                {
                    res[j++] = s[i];
                }
            }
        }
        else
        {
            if (s[i] == ' ')
            {
                continue;
            }
            if (s[i] == punctuation[0] || s[i] == punctuation[1] || s[i] == punctuation[2] || s[i] == punctuation[3])
            {
                continue;
            }
            else
            {
                res[j++] = s[i];
            }
        }
    }

    res[j] = '\0';
    printf("The string after removing consecutive spaces and adding a space after punctuation marks is: %s\n", res);

    return 0;
}

