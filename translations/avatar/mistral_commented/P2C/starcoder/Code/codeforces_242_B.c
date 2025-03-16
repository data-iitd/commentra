#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>

int main()
{
    int n, l, r, li, ri, id = 0;
    scanf("%d", &n);
    scanf("%d %d", &l, &r);
    for(int i = 1; i < n; i++)
    {
        scanf("%d %d", &li, &ri);
        if(li <= l && r <= ri)
        {
            id = i;
        }
        else if(li < l || r < ri)
        {
            id = n;
        }
        l = min(l, li);
        r = max(r, ri);
    }
    printf("%d\n", -1 if(id == n) else id + 1);
    return 0;
}

