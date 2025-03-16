#include<stdio.h>
int main()
{
    int a,b;
    scanf("%d",&a);
    b=a/(60*60);
    a=a%(60*60);
    printf("%d:%d:%d\n",b,a/60,a%60);
    return 0;
}
