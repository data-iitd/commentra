#include <stdio.h>
#include <stdlib.h>
int main()
{
    int N,P;
    scanf("%d %d",&N,&P);
    int a[N];
    for(int i=0;i<N;i++)
    {
        scanf("%d",&a[i]);
    }
    int one=0,zero=0;
    for(int i=0;i<N;i++)
    {
        if(a[i]==1)
        {
            one++;
        }
        else
        {
            zero++;
        }
    }
    int pattern_a=0,pattern_b=0;
    for(int j=0;j<=zero;j++)
    {
        pattern_b+=comb(zero,j);
    }
    int time=0;
    while(time<=one)
    {
        if(time%2==P)
        {
            pattern_a+=comb(one,time);
        }
        time++;
    }
    printf("%d",pattern_a*pattern_b);
    return 0;
}
