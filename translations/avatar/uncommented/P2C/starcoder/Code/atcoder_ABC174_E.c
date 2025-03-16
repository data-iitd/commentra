#include <stdio.h>
#include <stdlib.h>
int main()
{
    int n,k,i,j,ans,mid,a,b;
    scanf("%d%d",&n,&k);
    int lis[n];
    for(i=0;i<n;i++)
        scanf("%d",&lis[i]);
    a=1;
    b=*max_element(lis,lis+n);
    ans=b;
    while(a<=b)
    {
        mid=(a+b)/2;
        j=0;
        for(i=0;i<n;i++)
        {
            if(lis[i]%mid==0)
                j++;
            j-=lis[i]/mid;
        }
        if(j>=k)
            ans=mid;
        else
            a=mid+1;
    }
    printf("%d",ans);
    return 0;
}
