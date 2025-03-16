#include <stdio.h>
#include <stdlib.h>

int main()
{
    int len, i, l, r, flag;
    scanf("%d", &len);
    int a[len];
    for(i=0; i<len; i++)
        scanf("%d", &a[i]);
    l = 0;
    r = 0;
    flag = 0;
    for(i=0; i<len; i++)
    {
        if(a[i]!= i+1 && flag == 0)
        {
            l = i+1;
            flag = 1;
            continue;
        }
        if(a[i]!= i+1 && flag == 1)
        {
            r = i+1;
            if(a[r-1] - a[r-2] > 0)
            {
                printf("%d %d", l, r);
                break;
            }
        }
    }
    if(flag == 0)
        printf("0 0");
    return 0;
}
