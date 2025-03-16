
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>

int main()
{
    char str[1000000];
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
    else if(str[dotIndex+1]>4)
    {
        char _str[1000000];
        for(int i=0;i<dotIndex;i++)
        {
            _str[i]=str[i];
        }
        _str[dotIndex]='\0';
        printf("%s\n",strcat(_str,"1"));
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

