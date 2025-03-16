#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char s[100000];
    scanf("%s", s);
    int len = strlen(s);
    char targ[len];
    for (int i = 0; i < len; i++)
    {
        targ[i] = s[i];
    }
    int count[26] = {0};
    for (int i = 0; i < len; i++)
    {
        count[targ[i] - 'a']++;
    }
    int count2[26] = {0};
    for (int i = 0; i < len; i++)
    {
        if (count[targ[i] - 'a'] == 2)
        {
            count2[targ[i] - 'a']++;
        }
    }
    int count3 = 0;
    for (int i = 0; i < 26; i++)
    {
        if (count2[i] == 1)
        {
            count3++;
        }
    }
    if (count3 == 2)
    {
        printf("Yes");
    }
    else
    {
        printf("No");
    }
    return 0;
}
