#include <stdio.h>
#include <string.h>

int main()
{
    char s[100];
    char result[100];
    int i = 0;

    printf("Enter a string: ");
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

    printf("Result: %s\n", result);

    return 0;
}

