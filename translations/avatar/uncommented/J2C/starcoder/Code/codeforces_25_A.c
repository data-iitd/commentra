#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n,i,array[100000],even,odd,even_ind,odd_ind;
    scanf("%d",&n);
    for(i=1;i<=n;i++)
    {
        scanf("%d",&array[i]);
    }
    even=0;
    odd=0;
    for(i=1;i<=n;i++)
    {
        if(array[i]%2==0)
        {
            even++;
            even_ind=i;
        }
        else
        {
            odd++;
            odd_ind=i;
        }
    }
    if(odd>even)
    {
        printf("%d",even_ind);
    }
    else
    {
        printf("%d",odd_ind);
    }
    return 0;
}
