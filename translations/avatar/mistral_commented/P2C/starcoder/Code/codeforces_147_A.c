#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char s[1000];
    char res[1000];
    char punctuation[] = ",.!?";
    int i,j;

    scanf("%s",s);

    for(i=0;i<strlen(s);i++)
    {
        if(i>=1)
        {
            if(s[i]==' ')
            {
                if(res[strlen(res)-1]!=' ')
                {
                    res[strlen(res)]=' ';
                }
                else
                {
                    continue;
                }
            }
        }
        else if(strchr(punctuation,s[i]))
        {
            if(res[strlen(res)-1]==' ')
            {
                res[strlen(res)-1]='\0';
                res[strlen(res)]=s[i];
                res[strlen(res)+1]='\0';
            }
            else
            {
                res[strlen(res)]=s[i];
            }
        }
        else
        {
            res[strlen(res)]=s[i];
        }
    }
    printf("%s",res);
    return 0;
}
