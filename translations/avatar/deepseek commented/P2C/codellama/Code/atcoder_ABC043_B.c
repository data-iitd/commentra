
#include <stdio.h>
#include <string.h>

int main()
{
    char s[100];
    char my_str[100] = "";
    int i, j;

    printf("Enter a string: ");
    scanf("%s", s);

    for (i = 0; s[i] != '\0'; i++)
    {
        if (s[i] == '0' || s[i] == '1')
        {
            my_str[j] = s[i];
            j++;
        }
        else if (s[i] == 'B' && strlen(my_str) != 0)
        {
            my_str[strlen(my_str) - 1] = '\0';
        }
    }

    printf("The modified string is: %s\n", my_str);

    return 0;
}

