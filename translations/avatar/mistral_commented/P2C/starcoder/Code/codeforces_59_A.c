#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char txt[1000];
    int cu = 0, cl = 0;
    scanf("%s", txt);
    for (int i = 0; i < strlen(txt); i++)
    {
        if (txt[i] >= 'A' && txt[i] <= 'Z')
            cu++;
        else if (txt[i] >= 'a' && txt[i] <= 'z')
            cl++;
    }
    if (cu > cl)
    {
        for (int i = 0; i < strlen(txt); i++)
            txt[i] = toupper(txt[i]);
    }
    else
    {
        for (int i = 0; i < strlen(txt); i++)
            txt[i] = tolower(txt[i]);
    }
    printf("%s", txt);
    return 0;
}
