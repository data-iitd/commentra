#include <stdio.h>
#include <string.h>

int main()
{
    char txt[100];
    int cu = 0, cl = 0, i;

    printf("Enter a string: ");
    scanf("%s", txt);

    for (i = 0; i < strlen(txt); i++)
    {
        if (txt[i] >= 'a' && txt[i] <= 'z')
            cl++;
        else
            cu++;
    }

    if (cu > cl)
        for (i = 0; i < strlen(txt); i++)
            txt[i] = toupper(txt[i]);
    else
        for (i = 0; i < strlen(txt); i++)
            txt[i] = tolower(txt[i]);

    printf("Output: %s\n", txt);

    return 0;
}

