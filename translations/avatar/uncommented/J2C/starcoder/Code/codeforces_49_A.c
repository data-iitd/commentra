#include <stdio.h>
#include <stdlib.h>

int main()
{
    char s[1000];
    scanf("%s",s);
    int length = strlen(s);
    char ch = 0;
    for(int i=length-1;i>=0;i--)
    {
        if(s[i]!=''&& s[i]!='?')
        {
            ch = s[i];
            break;
        }
    }
    ch = tolower(ch);
    if(ch=='a' || ch=='e' || ch=='i' || ch=='o' || ch=='u' || ch=='y')
    {
        printf("YES");
    }
    else
    {
        printf("NO");
    }
    return 0;
}
