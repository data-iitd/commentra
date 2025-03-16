#include <stdio.h>
#include <stdlib.h>

int main()
{
    char str[100000];
    scanf("%s",str);
    long k;
    scanf("%ld",&k);
    int n=strlen(str);
    for(int i=0;i<k;i++)
    {
        if(str[i]=='1')
        {
            if(i==k-1)
            {
                printf("1");
                return 0;
            }
        }
        else
        {
            printf("%c",str[i]);
            return 0;
        }
    }
}
