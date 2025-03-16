#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>
#include <ctype.h>
#include <limits.h>
#include <float.h>
#include <time.h>
#include <assert.h>

int main()
{
    int a,i,max,min;
    scanf("%d",&a);
    int ar[a];
    for(i=0;i<a;i++)
    {
        scanf("%d",&ar[i]);
    }
    max=0;
    min=0;
    for(i=0;i<a;i++)
    {
        max=max(ar[i]-ar[0],ar[a-1]-ar[i]);
        if(i==0)
            min=ar[i+1]-ar[i];
        else if(i==a-1)
            min=ar[i]-ar[i-1];
        else
            min=min(ar[i]-ar[i-1],ar[i+1]-ar[i]);
        printf("%d %d\n",min,max);
    }
    return 0;
}
