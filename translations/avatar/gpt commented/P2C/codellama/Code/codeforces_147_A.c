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
                    res[j] = s[i];
                    j++;
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
                    res[j] = s[i];
                    j++;
                    res[j] = ' ';
                    j++;
                }
                else
                {
                    res[j] = s[i];
                    j++;
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
                res[j] = s[i];
                j++;
            }
        }
    }

    printf("The modified string is: %s\n", res);

    return 0;
}

