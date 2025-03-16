#######
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char s[100000];
    scanf("%s",s);
    int n=strlen(s);
    char c=s[0];
    char ans[100000];
    ans[0]=c;
    int i=1;
    while(i<n)
    {
        c=s[i];
        if(c>='a'&&c<='z')
        {
            if(ans[i-1]>='a'&&ans[i-1]<='z')
            {
                ans[i]=' ';
                i++;
            }
            ans[i]=c;
            i++;
        }
        else if(c>='A'&&c<='Z')
        {
            if(ans[i-1]>='A'&&ans[i-1]<='Z')
            {
                ans[i]=' ';
                i++;
            }
            ans[i]=c;
            i++;
        }
        else if(c>='0'&&c<='9')
        {
            ans[i]=c;
            i++;
        }
        else if(c=='.'||c==','||c=='!'||c=='?')
        {
            ans[i]=c;
            i++;
        }
    }
    ans[i]='\0';
    printf("%s",ans);
    return 0;
}

