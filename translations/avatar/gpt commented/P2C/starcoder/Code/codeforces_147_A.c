#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char s[1000];
    scanf("%s", s);

    char res[1000];
    res[0] = '\0';

    char punctuation[] = {',', '.', '!', '?'};

    for (int i = 0; s[i]!= '\0'; i++)
    {
        if (i >= 1)
        {
            if (s[i] =='')
            {
                if (res[strlen(res) - 1]!='')
                {
                    strcat(res, " ");
                }
                else
                {
                    continue;
                }
            }
            else
            {
                if (strchr(punctuation, s[i])!= NULL)
                {
                    if (res[strlen(res) - 1] =='')
                    {
                        res[strlen(res) - 1] = '\0';
                    }
                    strcat(res, s[i]);
                    strcat(res, " ");
                }
                else
                {
                    strcat(res, s[i]);
                }
            }
        }
        else
        {
            if (s[i] =='')
            {
                continue;
            }
            if (strchr(punctuation, s[i])!= NULL)
            {
                continue;
            }
            else
            {
                strcat(res, s[i]);
            }
        }
    }

    printf("%s", res);

    return 0;
}
