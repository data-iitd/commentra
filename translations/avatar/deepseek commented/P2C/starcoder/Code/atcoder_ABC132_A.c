
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char S[100000];
    scanf("%s", S);
    int c[26] = {0};
    for (int i = 0; i < strlen(S); i++)
    {
        c[S[i] - 'a']++;
    }
    int flag = 0;
    for (int i = 0; i < 26; i++)
    {
        if (c[i]!= 2)
        {
            flag = 1;
            break;
        }
    }
    if (flag)
    {
        printf("No");
    }
    else
    {
        printf("Yes");
    }
    return 0;
}

