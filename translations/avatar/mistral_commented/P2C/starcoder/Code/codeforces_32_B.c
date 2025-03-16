#include <stdio.h>
#include <string.h>

int main(void)
{
    char s[1000];
    char result[1000];
    int i = 0;

    scanf("%s", s);

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
