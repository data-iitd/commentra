#include <stdio.h>
#include <string.h>

int main()
{
    char s[100];
    char result[100];

    scanf("%s", s);

    if (strstr(s, "A") && strstr(s, "B"))
    {
        strcpy(result, "Yes");
    }
    else
    {
        strcpy(result, "No");
    }

    printf("%s\n", result);

    return 0;
}

