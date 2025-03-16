
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

int main()
{
    char s[100];
    scanf("%s", s);
    int len = strlen(s);
    int count[26] = {0};
    for (int i = 0; i < len; i++)
    {
        count[s[i] - 'a']++;
    }
    bool ok = true;
    for (int i = 0; i < 26; i++)
    {
        if (count[i] != 2)
        {
            ok = false;
            break;
        }
    }
    if (ok)
    {
        printf("Yes\n");
    }
    else
    {
        printf("No\n");
    }
    return 0;
}

