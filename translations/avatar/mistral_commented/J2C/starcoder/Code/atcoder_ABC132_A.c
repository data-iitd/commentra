
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char s[100000];
    scanf("%s",s);
    int len=strlen(s);
    int i,j,k,count=0;
    char c;
    for(i=0;i<len;i++)
    {
        c=s[i];
        for(j=i+1;j<len;j++)
        {
            if(c==s[j])
            {
                count++;
            }
        }
        if(count!=2)
        {
            printf("No\n");
            return 0;
        }
        count=0;
    }
    if(len==2)
    {
        printf("Yes\n");
    }
    else
    {
        printf("No\n");
    }
    return 0;
}

