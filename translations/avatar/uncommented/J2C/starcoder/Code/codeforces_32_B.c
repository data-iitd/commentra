#include <stdio.h>
#include <stdlib.h>

int main()
{
    char n[1000];
    scanf("%s",n);
    int i,j,k,l;
    for(i=0;i<strlen(n);i++)
    {
        if(n[i]=='.')
        {
            if(k==1)
            {
                printf("1");
                k=0;
            }
            else
            {
                printf("0");
            }
        }
        else
        {
            if(k==1)
            {
                printf("2");
                k=0;
            }
            else
            {
                k=1;
            }
        }
    }
    return 0;
}
