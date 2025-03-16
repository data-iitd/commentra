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
        scanf("%d",&a);
        a+=a;
    }
    for(int i=0;i<n-1;i++)
    {
        scanf("%d",&b);
        b+=b;
    }
    for(int i=0;i<n-2;i++)
    {
        scanf("%d",&c);
        c+=c;
    }
    x=a-b;
    y=b-c;
    printf("%d\n",x);
    printf("%d\n",y);
    return 0;
}
