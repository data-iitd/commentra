
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>

int main()
{
    int len, a[100000], l, r, i, flag, isTrue;
    scanf("%d", &len);
    for(i = 0; i < len; i++)
        scanf("%d", &a[i]);
    l = 0;
    r = 0;
    flag = 0;
    isTrue = 0;
    for(i = 0; i < len; i++)
    {
        if(a[i]!= i + 1 &&!flag)
        {
            l = i + 1;
            flag = 1;
            continue;
        }
        if(a[i]!= i + 1 && flag)
        {
            r = i + 1;
            if(a[r - 1] - a[r - 2] > 0)
            {
                isTrue = 1;
                break;
            }
        }
    }
    printf("%d %d\n", (isTrue == 0)? l : 0, (isTrue == 0)? r : 0);
    return 0;
}

