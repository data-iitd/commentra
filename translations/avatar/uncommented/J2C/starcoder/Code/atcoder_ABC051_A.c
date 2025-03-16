#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char a[100000];
    scanf("%s",a);
    int i,j,k=0;
    for(i=0;a[i]!='\0';i++)
    {
        if(a[i]!=' ')
        {
            a[k++]=a[i];
        }
    }
    a[k]='\0';
    printf("%s",a);
    return 0;
}
