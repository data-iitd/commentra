#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char s[1000];
    scanf("%s", s);
    char res[1000];
    int i, j;
    for (i = 0; i < strlen(s); i++)
    {
        if (i >= 1)
        {
            if (s[i] =='')
            {
                if (res[j - 1]!='')
                {
                    res[j] = s[i];
                    j++;
                }
                else
                {
                    continue;
                }
            }
            else
            {
                if (s[i] == ',' || s[i] == '.' || s[i] == '!' || s[i] == '?')
                {
                    if (res[j - 1] =='')
                    {
                        j--;
                    }
                    res[j] = s[i];
                    j++;
                    res[j] ='';
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
            if (s[i] =='')
            {
                continue;
            }
            if (s[i] == ',' || s[i] == '.' || s[i] == '!' || s[i] == '?')
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
    res[j] = '\0';
    printf("%s", res);
    return 0;
}

