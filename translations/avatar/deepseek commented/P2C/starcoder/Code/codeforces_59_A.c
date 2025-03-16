#include <stdio.h>
#include <stdlib.h>

int main()
{
    char txt[1000];
    int cu = 0, cl = 0;

    scanf("%s", txt);

    for (int z = 0; txt[z]!= '\0'; z++)
    {
        if (txt[z] >= 'a' && txt[z] <= 'z')
            cl++;
        else
            cu++;
    }

    if (cu > cl)
        for (int z = 0; txt[z]!= '\0'; z++)
            txt[z] = toupper(txt[z]);
    else
        for (int z = 0; txt[z]!= '\0'; z++)
            txt[z] = tolower(txt[z]);

    printf("%s", txt);

    return 0;
}

