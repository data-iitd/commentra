#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

int main(int argc, char *argv[])
{
    char s[100000];
    scanf("%s", s);
    char targ[100000];
    strcpy(targ, s);
    int len = strlen(targ);
    bool ok = true;
    int count[26] = {0};
    for (int i = 0; i < len; i++)
    {
        count[targ[i] - 'a']++;
    }
    for (int i = 0; i < 26; i++)
    {
        if (count[i]!= 2)
        {
            ok = false;
            break;
        }
    }
    if (ok && strlen(targ) == 2)
    {
        printf("Yes\n");
    }
    else
    {
        printf("No\n");
    }
    return 0;
}

