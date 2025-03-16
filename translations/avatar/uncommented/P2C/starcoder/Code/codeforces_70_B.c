#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int main()
{
    int n,ans,sumL;
    scanf("%d",&n);
    ans=1;
    sumL=0;
    char s[100000];
    scanf("%s",s);
    for(int i=0;s[i]!='\0';i++)
    {
        if(s[i]=='.')
        {
            s[i]='\0';
            if(strlen(s)>1)
            {
                if(strlen(s)>n)
                {
                    printf("Impossible");
                    exit(0);
                }
                if(sumL+strlen(s)+(sumL>0)>n)
                {
                    ans++;
                    sumL=strlen(s);
                }
                else
                {
                    sumL=sumL+strlen(s)+(sumL>0);
                }
            }
        }
    }
    printf("%d",ans);
    return 0;
}
