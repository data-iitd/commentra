#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>

int main()
{
    int len, a[100000], l, r, flag, isTrue;
    scanf("%d", &len);
    for(int i = 0; i < len; i++)
        scanf("%d", &a[i]);
    l = 0;
    r = 0;
    flag = false;
    isTrue = false;
    for(int i = 0; i < len; i++)
    {
        if(a[i]!= i + 1 &&!flag)
        {
            l = i + 1;
            flag = true;
            continue;
        }
        if(a[i]!= i + 1 && flag)
        {
            r = i + 1;
            if((a[r - 1] - a[r - 2] > 0))
            {
                isTrue = true;
                break;
            }
        }
    }
    if(!isTrue)
        printf("%d %d", l, r);
    else
        printf("0 0");
    return 0;
}

