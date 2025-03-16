#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    char n[100000];
    scanf("%s",n);
    int s=0;
    for(int i=0;i<strlen(n);i++)
    {
        if(n[i]=='.')
        {
            if(s)
            {
                printf("1");
                s=0;
            }
            else
            {
                printf("0");
            }
        }
        else
        {
            if(s)
            {
                printf("2");
                s=0;
            }
            else
            {
                s=1;
            }
        }
    }
    return 0;
}

