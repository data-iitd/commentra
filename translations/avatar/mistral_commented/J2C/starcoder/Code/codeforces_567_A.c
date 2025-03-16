#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n,i,j,max,min;
    scanf("%d",&n);
    int a[n];
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    for(i=0;i<n;i++)
    {
        max=a[i]-a[0];
        min=a[i]-a[i];
        for(j=i+1;j<n;j++)
        {
            if(a[j]-a[i]>max)
            {
                max=a[j]-a[i];
            }
            if(a[j]-a[i]<min)
            {
                min=a[j]-a[i];
            }
        }
        printf("%d %d\n",min,max);
    }
    return 0;
}
