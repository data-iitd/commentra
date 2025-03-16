
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main()
{
    char s[100];
    int l, i, cnt = 0;
    char ans[100] = "AC";

    scanf("%s", s);
    l = strlen(s);

    if (s[0] != 'A')
        strcpy(ans, "WA");

    for (i = 1; i < l; i++)
    {
        if (isupper(s[i]))
        {
            if (i == 1 || i == l - 1 || s[i] != 'C')
                strcpy(ans, "WA");
            cnt++;
        }
    }

    if (cnt != 1)
        strcpy(ans, "WA");

    printf("%s\n", ans);

    return 0;
}

