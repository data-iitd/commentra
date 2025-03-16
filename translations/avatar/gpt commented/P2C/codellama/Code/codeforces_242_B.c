#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define I(x) (int*)malloc(sizeof(int)*x)
#define IS() (char*)malloc(sizeof(char)*100)
#define IN() (int)malloc(sizeof(int))
#define IF() (float)malloc(sizeof(float))

int main()
{
    int n, i, l, r, li, ri, id = 0;
    scanf("%d", &n);
    scanf("%d %d", &l, &r);
    for (i = 1; i < n; i++)
    {
        scanf("%d %d", &li, &ri);
        if (li <= l && r <= ri)
            id = i;
        else if (li < l || r < ri)
            id = n;
        l = min(l, li);
        r = max(r, ri);
    }
    printf("%d", -1 + id);
    return 0;
}

