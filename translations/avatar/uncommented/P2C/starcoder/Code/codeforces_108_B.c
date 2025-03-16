#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a[100000];
    int i,j,n;
    scanf("%d",&n);
    for(i=0;i<n;i++)
        scanf("%d",&a[i]);
    for(i=0;i<n-1;i++)
    {
        if(a[i]!=a[i+1] && a[i]<a[i+1]*2)
        {
            printf("YES");
            return 0;
        }
    }
    printf("NO");
    return 0;
}
