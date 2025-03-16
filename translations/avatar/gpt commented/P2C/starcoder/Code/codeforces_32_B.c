#include <stdio.h>
#include <string.h>

int main()
{
    char s[1000];
    scanf("%s", s);

    char result[1000];
    int i = 0;

    while (i < strlen(s))
    {
        if (s[i] == '.')
        {
            result[i] = '0';
        }
        else
        {
            i++;
            if (s[i] == '.')
            {
                result[i] = '1';
            }
            else
            {
                result[i] = '2';
            }
        }
        i++;
    }

    printf("%s", result);

    return 0;
}

