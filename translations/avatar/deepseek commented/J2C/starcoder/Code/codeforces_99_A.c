
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>

int main()
{
    char str[100000];
    scanf("%s",str);
    int dotIndex=0;
    for(int i=0;i<strlen(str);i++)
    {
        if(str[i]=='.')
        {
            dotIndex=i;
            break;
        }
    }
    if(str[dotIndex-1]=='9')
    {
        printf("GOTO Vasilisa.\n");
    }
    else if(str[dotIndex+1]>='4')
    {
        char _str[100000];
        int i=0;
        for(;i<dotIndex;i++)
        {
            _str[i]=str[i];
        }
        _str[i]='\0';
        int num=atoi(_str);
        num++;
        printf("%d\n",num);
    }
    else
    {
        for(int i=0;i<dotIndex;i++)
        {
            printf("%c",str[i]);
        }
        printf("\n");
    }
    return 0;
}

