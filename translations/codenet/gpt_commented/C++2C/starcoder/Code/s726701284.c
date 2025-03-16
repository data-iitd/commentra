#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main()
{
    char s[1000];
    scanf("%s",s);
    for(int i=97;i<=122;i++)
    {
        int a=0;
        for(int j=0;j<strlen(s);j++)
        {
            if(i==s[j])
            {
                a++;
            }
        }
        if(a==0)
        {
            printf("%c\n",i);
            break;
        }
        if(i==122)
        {
            printf("None\n");
            break;
        }
    }
}
