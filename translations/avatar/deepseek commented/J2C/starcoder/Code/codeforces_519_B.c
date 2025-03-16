
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n,a,b,c,x,y;
    scanf("%d",&n);
    a=0;
    b=0;
    c=0;
    for(int i=0;i<n;i++)
    {
        scanf("%d",&x);
        a+=x;
    }
    for(int i=0;i<n-1;i++)
    {
        scanf("%d",&x);
        b+=x;
    }
    for(int i=0;i<n-2;i++)
    {
        scanf("%d",&x);
        c+=x;
    }
    x=a-b;
    y=b-c;
    printf("%d\n%d",x,y);
    return 0;
}

