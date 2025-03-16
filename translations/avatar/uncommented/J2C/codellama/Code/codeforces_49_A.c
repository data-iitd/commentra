
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main()
{
    char s[100];
    int length;
    char ch = 0;

    scanf("%s", s);
    length = strlen(s);

    for (int i = length - 1; i >= 0; i--)
    {
        if (s[i] != ' ' && s[i] != '?')
        {
            ch = s[i];
            break;
        }
    }

    ch = tolower(ch);

    if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u' || ch == 'y')
    {
        printf("YES\n");
    }
    else
    {
        printf("NO\n");
    }

    return 0;
}

