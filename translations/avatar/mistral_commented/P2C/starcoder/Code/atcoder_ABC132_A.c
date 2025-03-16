#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char S[100000];
    scanf("%s", S);
    int len = strlen(S);
    int count[26] = {0};
    for(int i=0; i<len; i++)
    {
        count[S[i]-'a']++;
    }
    int flag = 0;
    for(int i=0; i<26; i++)
    {
        if(count[i]!=2)
        {
            flag = 1;
            break;
        }
    }
    if(flag)
    {
        printf("No");
    }
    else
    {
        printf("Yes");
    }
    return 0;
}

