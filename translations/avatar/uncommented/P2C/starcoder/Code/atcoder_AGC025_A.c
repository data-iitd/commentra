#include <stdio.h>
#include <stdlib.h>

int main()
{
    char n[100];
    scanf("%s",n);
    int a[5] = {10,100,1000,10000,100000};
    int new = 0;
    for(int i=0;i<strlen(n);i++)
    {
        new += n[i] - '0';
    }
    if(new==10)
    {
        printf("10");
    }
    else if(new==100)
    {
        printf("100");
    }
    else if(new==1000)
    {
        printf("1000");
    }
    else if(new==10000)
    {
        printf("10000");
    }
    else if(new==100000)
    {
        printf("100000");
    }
    else
    {
        printf("%d",new);
    }
    return 0;
}

