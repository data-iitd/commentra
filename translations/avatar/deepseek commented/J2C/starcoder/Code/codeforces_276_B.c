
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char str[100000];
    scanf("%s",str);
    int len=strlen(str);
    int map[26]={0};
    int odd=0;
    for(int i=0;i<len;i++)
    {
        map[str[i]-'a']++;
    }
    for(int i=0;i<26;i++)
    {
        if(map[i]%2!=0)
        {
            odd++;
        }
    }
    if(odd<=1||odd%2!=0)
    {
        printf("First\n");
    }
    else
    {
        printf("Second\n");
    }
    return 0;
}

