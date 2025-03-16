#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char s[100000], t[100000];
    scanf("%s", s);
    scanf("%s", t);
    
    int ss[26] = {0}, tt[26] = {0};
    for (int i = 0; i < strlen(s); i++)
    {
        ss[s[i] - 'a']++;
    }
    for (int i = 0; i < strlen(t); i++)
    {
        tt[t[i] - 'a']++;
    }
    
    int i;
    for (i = 0; i < 26; i++)
    {
        if (ss[i]!= tt[i])
        {
            break;
        }
    }
    if (i == 26)
    {
        printf("Yes");
    }
    else
    {
        printf("No");
    }
    
    return 0;
}

