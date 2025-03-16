#include <stdio.h>
#include <string.h>

int main(void)
{
    char s[1000];
    scanf("%s", s);
    int i = 0;
    char result[1000];
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
